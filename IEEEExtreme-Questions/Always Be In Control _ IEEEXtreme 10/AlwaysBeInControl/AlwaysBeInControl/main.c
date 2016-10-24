#include <stdio.h>
#include <stdlib.h>

float A_2[]={1.880,1.023,0.729,0.577,0.483,0.419,0.373,0.337,0.308};//2 3 4 5 6 7 8 9 10
int getline_ex(int s[],int lim);
int main()
{
    int L,*DAT=(int *)malloc(sizeof(int)*100);
    scanf("%d",&L);
    getline_ex(DAT,1000);

    int Point_Num=*DAT;
    int GPoint_Num=*(DAT+1);
    int Group_Num=Point_Num/GPoint_Num;
    int *DATA=DAT+2;
    float A2=A_2[GPoint_Num-2];
    float SubAver[GPoint_Num];
    float SubRang[GPoint_Num];
    float sum=0;
    int i=0,j=0,max,min;
    float Aver_Aver=0,Range_Aver=0;
    for(i=0;i<Group_Num-1;i++)
    {
        sum=0;
        max=*(DATA+GPoint_Num*i);
        min=*(DATA+GPoint_Num*i);
        for(j=0;j<GPoint_Num-1;j++)
        {
            sum+=*(DATA+GPoint_Num*i+j);
            if(max<=*(DATA+GPoint_Num*i+j)) max=*(DATA+GPoint_Num*i+j);
            if(min>=*(DATA+GPoint_Num*i+j)) min=*(DATA+GPoint_Num*i+j);
        }
        SubAver[i]=sum/GPoint_Num;
        SubRang[i]=max-min;
        Aver_Aver+=SubAver[i]/Group_Num;
        Range_Aver+=SubRang[i]/Group_Num;
    }
    float UCL=Aver_Aver+A2*Range_Aver,LCL=Aver_Aver-A2*Range_Aver,CL=Aver_Aver,Sigma=(UCL-CL)/3;
    int expression1=0,expression2=0,Flag2=0,expression3=0,Flag3=0,expression4=0,Flag4=0;
    for(i=0;i<Point_Num-1;i++)
    {
        expression1=expression1 || (*(DATA+i)>=UCL || *(DATA+i)<=LCL);
    }
    if(expression1) { printf("Out of Control"); return 0; }
    for(i=0;i<Point_Num-1;i++)
    {
        if((*(DATA+i)>=2*Sigma+CL || *(DATA+i)<=-2*Sigma+CL)) Flag2++;
        if(Flag2>=2) expression2=1;
    }
    if(expression2) { printf("Out of Control"); return 0; }
    for(i=0;i<Point_Num-1;i++)
    {
        if((*(DATA+i)>=Sigma+CL || *(DATA+i)<=-1*Sigma+CL)) Flag3++;
        if(Flag3>=4) expression3=1;
    }
    if(expression3) { printf("Out of Control"); return 0; }
    for(i=0;i<Point_Num-1;i++)
    {
        if(*(DATA+i)>=CL) Flag4++;
        if(Flag4>=8) expression4=1;
    }
    if(expression4) { printf("Out of Control"); return 0; }
    printf("In Control"); return 0;
}
int getline_ex(int s[],int lim){
    int c=getchar();
    int i=0;
    do{
        if (c!='\n'&&c!=EOF) {
            s[i++] = c;
        }
        c=getchar();
        if (c=='\n'||c==EOF) {
            break;
        }
    }
    while(i<lim);
    s[i]='\0';
    return i;
}
