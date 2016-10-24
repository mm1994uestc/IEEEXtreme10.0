#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FIFO(int p,int s,int n,int P[]);
int LRU(int p,int s,int n,int P[]);

int main()
{
    int t;
    int i,j;
    scanf("%d",&t);
    int p[t],s[t],n[t];
    scanf("%d %d %d",p,s,n);
    int Adress[t][n[t]];
    int Page_Require[n[t]];
    int FIFO_Score[t];
    int LRU_Score[t];
    for(i=0;i<t;i++)
    {
        for(j=0;j<n[t];j++)
        {
            scanf("%d",&Adress[i][j]);
        }
    }
    for(i=0;i<t;i++)
    {
        for(j=0;j<n[t];j++)
        {
            Page_Require[j]=floor(Adress[i][j]/s[i]);
        }
        FIFO_Score[i]=FIFO(p[i],s[i],n[i],Page_Require);
        LRU_Score[i]=LRU(p[i],s[i],n[i],Page_Require);
        if(LRU_Score[i]>=FIFO_Score[i])  printf("yes %d %d",FIFO_Score[i],LRU_Score[i]);
        else printf("no %d %d",FIFO_Score[i],LRU_Score[i]);
        printf("\n");
    }
    return 0;
}
int FIFO(int p,int s,int n,int P[])
{
    int Cycle;
    int Page_state[p]={0};
    int Replace_time=0;
    for(Cycle=1;Cycle<=n;Cycle++)
    {
        if(P[Cycle-1])
    }
    return 0;
}
int LRU(int p,int s,int n,int P[])
{

    return 0;
}
