#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Path_search(int X,int Y,int N,int *Maz);
int Direct[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int main()
{
    int N=10,X[100]={0},Y[100]={0},Count=0,Starttime=0;
    scanf("%d",&N);
    int A=0,B=0,i=0,j=0;//Temp[N][N];
    int *Maze=(int *)malloc(sizeof(int)*N*N);
    int Start_X=0,Start_Y=0;
    do{
        scanf("%d %d",&X[Count],&Y[Count]);
        //gets(&X[Count]);
        if(X[Count]==1) Starttime++;
        Count++;
    }while(X[Count-1]!=-1);
    Count--;//保证数组大小正确
    printf("Input Finished");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            *(Maze+i*N+j)=0;
            //Temp[i][j]=0;
        }
    }
    int *Point_Maze=Maze;
    for(i=0;i<Count;i++)
    {
        A=X[i]-1;
        B=Y[i]-1;
        *(Point_Maze+A*N+B)=1;
        //Maze[A][B]=1;
        //*(Maze+A*N+B)=1;
        //Temp[(X[i]-1)][(Y[i]-1)]=1;
    }
    int Res[Starttime],MBOOL=0;
    for(i=0;i<Starttime;i++)
    {
        for(;j<N;j++)
        {
            if(Y[j]==1) { Start_X=X[j]-1; Start_Y=Y[j]-1;}
        }
        //memcpy(&Temp,&Maze,N);
        Res[i]=Path_search(Start_X,Start_Y,N,Maze);
        if(MBOOL!=0 || Res[i]!=0) MBOOL=1;
    }
    if(MBOOL)
    {
        printf("%d",Count);
    }
    else
    {
        printf("\n-1");
    }
    return 0;
}
int Path_search(int X,int Y,int N,int *Maz)
{
    *(Maz+X*N+Y)=0;
    if(Y==(N-1))
    {
        return 1;
    }
    else
    {
        int dir;
        for(dir=0;dir<4;dir++)
        {
            int X_Temp=X+Direct[dir][2];
            int Y_Temp=Y+Direct[dir][2];
            if(X_Temp<0 || X_Temp>N-1 || Y_Temp<0 || Y_Temp>N-1) continue;
            if(*(Maz+X_Temp*N+Y_Temp)==1)
            {
                *(Maz+X_Temp*N+Y_Temp)=0;
                if(Path_search(X_Temp,Y_Temp,N,Maz)) return 1;
            }
        }
        return 0;
    }
}
