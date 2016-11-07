#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <dos.h>
#include <conio.h>
#include <windows.h>

#define true 1
#define false 0

unsigned Montgomery(unsigned n, unsigned p, unsigned m);
char IsPrime3(unsigned n);
char isprime(int N);
int main()
{
    DWORD start, stop;
    start = GetTickCount();
    //Sleep(3000);
    int N=0;
    printf("Please enter a new number for calculate:");
    scanf("%d",&N);
    int Prime1=N;
    for(Prime1=N-4;Prime1>=1;Prime1--)
    {
        if(isprime(Prime1)) break;
    }
    N=N-Prime1;
    int Array[N],i=0,j=0;
    Array[0]=0;
    Array[1]=0;
    for(i=2;i<N;i++)
    {
        Array[i]=1;
    }
    for(i=2;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(j%i==0) Array[j]=0;
        }
    }
    for(i=2;i<N;i++)
    {
        if(Array[i]==1)
        {
            if(isprime((N-i)))
            {
                printf("The result is:%d %d %d\n",Prime1,i,N-i);
                break;
            }
        }
    }
    stop = GetTickCount();
    printf("The difference is: %lf seconds\n",stop-start);
    return 0;
}
char isprime(int N)
{
    if(N%2==0) return 0;
    int Max=sqrt(N),i=2;
    for(i=2;i<=Max;i++)
    {
        if(N%i==0) return 0;
    }
    return 1;
}
char IsPrime3(unsigned n)
{
    if ( n < 2 )
    {
        // С��2���������Ǻ���Ҳ��������
        return 0;
    }
    static unsigned aPrimeList[] = {
        2, 3, 5, 7, 11, 17, 19, 23, 29, 31, 41,
        43, 47, 53, 59, 67, 71, 73, 79, 83, 89, 97
    };
    const int nListNum = sizeof(aPrimeList) / sizeof(unsigned);
    int i=0;
    for (i=0;i<nListNum;++i)
    {
        // �����������е����Ե�ǰ���������ж�
        if (1!=Montgomery(aPrimeList[i],n-1,n)) // �ɸ������㷨
        {
            return false;
        }
    }
    return true;
}
unsigned Montgomery(unsigned n, unsigned p, unsigned m)
{ // ���ټ��� (n ^ e) % m ��ֵ����power�㷨������
    unsigned r = n % m; // �����r�ɲ���ʡ
    unsigned k = 1;
    while (p > 1)
    {
        if ((p & 1)!=0)
        {
            k = (k * r) % m; // ֱ��ȡģ
        }
        r = (r * r) % m; // ͬ��
        p /= 2;
    }
    return (r * k) % m; // ����ͬ��
}
