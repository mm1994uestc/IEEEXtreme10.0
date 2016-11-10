#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double MyPow(double Num,int N);
static double MySqrt(double Num,double P);
int main()
{
    double Ox=0,Oy=0,R=0;
    double x=0,y=0,D=0;
    char F=0;
    scanf("%lf %lf %lf",&Ox,&Oy,&R);
    scanf("%lf %lf",&x,&y);
    D=MySqrt(MyPow(x-Ox,2)+MyPow(y-Oy,2),0.002);
    if(D>R) F=-1;
    if(D<R) F=1;
    if(D==R) F=0;
    switch(F){
    case -1:printf("The axis(%f,%f) you input is out of the circle!\n",x,y); break;
    case 0 :printf("The axis(%f,%f) you input is on the boundary of the circle!\n",x,y); break;
    case 1 :printf("The axis(%f,%f) you input is located in the circle!\n",x,y); break;
        default: printf("The input format is error!\n"); break;
    }
    return 0;
}
static double MyPow(double Num,int N)
{
    int i=0;
    double Res=1;
    for(i=0;i<N;i++)
    {
        Res*=Num;
    }
    return Res;
}
static double MySqrt(double Num,double P)
{
    double r=Num/2,guess=2;
    while((r-guess)<P && (guess-r)<P)
    {
        r=(r+guess)/2;
        guess=Num/r;
    }
    return r;
}
