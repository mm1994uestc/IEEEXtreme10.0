#include <stdio.h>
#include <stdlib.h>
void sort(int A[],int n);

int main()
{
    int t=0;//1<t<5,�ܹ���t��Group
    scanf("%d",&t);
    int i=0,j=0;
    int * N=(int *)malloc(sizeof(int) *t);//��Ź�������
    int * K=(int *)malloc(sizeof(int) *t);//�������
    int *Size[t];//Dog-Size���ݴ�������Ѿ�����
    int *Node[t];//N������k-1���ָ�ڵ�node�Ĵ��
    int *Range[t];//��t��Group��K��range�Ĵ��
    for(j=0;j<t;j++)
    {
        scanf("%d %d",N+j,K+j);
        Size[j]=(int *)malloc(sizeof(int)*(*(N+j)));
        Node[j]=(int *)malloc(sizeof(int)*(*(K+j)-1));
        Range[j]=(int *)malloc(sizeof(int)*(*(K+j)));
        for(i=0;i<*(N+j);i++)
        {
            scanf("%d",(Size[j]+i));
        }
        printf("t is %c j is %d\n",t,j);
        sort(Size[j],*(N+j));//������е�������
    }

    //��ʼ�����ֵb-a
    for(j=0;j<t;j++)
    {
        //if(*(K+j)>1 && *(N+j)>*(K+j)) printf("Wrong input!");
        if(*(N+j)==1) { printf("0\n"); return 0;}
        //ȡ��ʼ�ķָ��Ϊ1--N/3--2*N/3--N
        for(i=0;i<*(K+j);i++)
        {
            if(i==0)
            {
                *(Node[j]+i)=0;//(*(N+j)/(*(K+j)));
            }
            else if(i==*(K+j)-1)
            {
                *(Node[j]+i)=*(N+j);//(*(N+j)/(*(K+j)));
            }
            else
            {
                *(Node[j]+i)=(int)(i*(*(N+j)/(*(K+j))));//����K���������ÿһ��(K-1��)�ڵ�node�ĳ�ʼλ��
            }
        }
        int Time=10;
        while(Time>=0)
        {
            for(i=0;i<*(K+j);i++)
            {
                *(Range[j]+i)=(int)(*(Size[j]+*(Node[j]+i))-*(Size[j]+*(Node[j]+i+1)))/(*(K+j));//����K���������ÿһ��(K��)�ָ����Ĵ洢
            }
            for(i=0;i<*(K+j);i++)
            {
                if(*(Range[j]+i)>*(Range[j]+i+1))
                {
                    *(Node[j]+i+1)=*(Node[j]+i+1)-1;
                }
                else
                {
                    *(Node[j]+i+1)=*(Node[j]+i+1)+1;
                }
            }
            Time--;
        }
    }
    return 0;
}

void sort(int A[],int n){
    int i,j,k;
    for(j=1;j<n;j++){
        i= j-1;
        k=A[j];
        while (i>=0&&k>A[i]) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = k;
    }

}
