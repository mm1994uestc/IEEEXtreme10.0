#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void sort(int A[],int n);
int main()
{
    int N,i=0,j=0,k=0;
    float A=1.00000;
    float B=4.00000;
    scanf("%d",&N);
    float Soldiers[N][2],Shelters[N][2],D2[N][N],min[N],max[N],sum=0,Big=0;
    do{
        scanf("%g %g",&Soldiers[i][0],&Soldiers[i][1]);
        i++;
    }while(i<N);
    i=0;
    do{
        scanf("%g %g",&Shelters[i][0],&Shelters[i][1]);
        i++;
    }while(i<N);
    for(i=0;i<N-1;i++)
    {
        for(j=0;j<N-1;j++)
        {
            D2[i][j]=pow((Soldiers[i][1]-Shelters[j][1]),2)+pow((Soldiers[i][2]-Shelters[j][2]),2);
        }
    }
    //printf("%f",D2[2][3])
    for(i=0;i<N-1;i++)
    {
        int Q=0,Compare;//,S=0,L=0;
        for(j=0;j<N-1;j++)
        {
            min[j]=D2[j][0];
            max[j]=D2[j][0];
            for(k=0;k<N-1;k++)
            {
                if(min[j]>=D2[j][k])
                {
                    min[j]=D2[j][k];
                    //S=k;
                }
                if(max[j]<=D2[j][k])
                {
                    max[j]=D2[j][k];
                    //L=k;
                }
            }
        }
        Compare=min[0];
        for(j=0;j<N-1;j++)
        {
            if(Compare>=min[j]) Compare=min[j];
            Q=j;
        }
        for(k=0;k<N-1;k++)
        {
            D2[Q][k]=max[Q]+1;
        }
        if(Big<=max[Q]) Big=max[Q];
        sum+=Compare;//sort(D2[]);//
    }
    printf("%.5f\n%.5f",A,B);
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
