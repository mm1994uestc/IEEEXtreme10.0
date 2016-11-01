#include <stdio.h>
#include <stdlib.h>

#define StonesBegin 26
#define StonesTakeM 3
#define NoGoodMv -1
#define false 0
#define true 1
static void Error(char i);
static int FindGoodMove(int Stone_N);
static int IsBadCondition(int Stone_N);
int main()
{
    int Stones=StonesBegin,Temp=0,StonesTaken=0,Flag=0;
    char T;
    enum {People,Comput}WhosTurn;
    printf("Stones' Amount? && You First?(y/n)");
    scanf("%d && %c",&Temp,&T);
    Stones=Temp;
    if(T=='y')
    {
        WhosTurn=People;
    }
    else
    {
        WhosTurn=Comput;
    }
    while(Stones>1)
    {
        printf("The Stone left is:%d\n",Stones);
        switch(WhosTurn)
        {
            case People:
                printf("People Please Select Stones You Want To Take:");
                scanf("%d",&StonesTaken); //printf("\n");
                if(StonesTaken>3 || StonesTaken<1) Error(1);
                Stones-=StonesTaken;
                WhosTurn=Comput;//�л����Ϊ����
                break;
            case Comput:
                printf("Comput Please Select Stones You Want To Take:");
                Flag=FindGoodMove(Stones);//���Բ��Ե�ʩչ
                //StonesTaken=(Flag==-1)? 1:Flag;
                if(Flag==NoGoodMv) StonesTaken=1;
                if(Flag!=NoGoodMv) StonesTaken=Flag;
                printf("%d\n",StonesTaken);
                Stones-=StonesTaken;
                WhosTurn=People;//�л����Ϊ��
                break;
        }
    }
    if(WhosTurn==People) printf("Congratulations!The Winner is Computer!\n");
    if(WhosTurn==Comput) printf("Congratulations!The Winner is People!\n");
    while(1);
    return 0;
}
static int FindGoodMove(int Stone_N)
{
    int i;
    for(i=1;i<=StonesTakeM;i++)
    {
        if(Stone_N<=i) return NoGoodMv;//�����ǰ��ʯ�ӵ�����������ȡ���࣬��ֱ������
        if(IsBadCondition(Stone_N-i)) {return i;}
    }
    return NoGoodMv;
}
static int IsBadCondition(int Stone_N)
{
    if(Stone_N==1) return true;
    return (FindGoodMove(Stone_N)==NoGoodMv);
}
static void Error(char i)
{
    if(i==1){ printf("The Stones you taken is illegal!"); while(1);}
}
