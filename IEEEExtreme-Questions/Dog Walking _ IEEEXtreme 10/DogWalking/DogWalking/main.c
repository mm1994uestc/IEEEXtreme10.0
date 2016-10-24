#include <stdio.h>
#include <stdlib.h>
void sort(int A[],int n);

int main()
{
    int t=0;//1<t<5,总共有t个Group
    scanf("%d",&t);
    int i=0,j=0;
    int * N=(int *)malloc(sizeof(int) *t);//存放狗的数量
    int * K=(int *)malloc(sizeof(int) *t);//存放人数
    int *Size[t];//Dog-Size数据存放数组已经排序
    int *Node[t];//N个数据k-1个分割节点node的存放
    int *Range[t];//第t个Group的K个range的存放
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
        sort(Size[j],*(N+j));//完成所有的排序工作
    }

    //开始计算差值b-a
    for(j=0;j<t;j++)
    {
        //if(*(K+j)>1 && *(N+j)>*(K+j)) printf("Wrong input!");
        if(*(N+j)==1) { printf("0\n"); return 0;}
        //取初始的分割点为1--N/3--2*N/3--N
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
                *(Node[j]+i)=(int)(i*(*(N+j)/(*(K+j))));//计算K个组里面的每一个(K-1个)节点node的初始位置
            }
        }
        int Time=10;
        while(Time>=0)
        {
            for(i=0;i<*(K+j);i++)
            {
                *(Range[j]+i)=(int)(*(Size[j]+*(Node[j]+i))-*(Size[j]+*(Node[j]+i+1)))/(*(K+j));//计算K个组里面的每一个(K个)分割结果的存储
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
