#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double round(double val);
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double S=100.0*100.0;
    int test=0,i=0,aa=0,eclipsenum=0;
    double x=0.0,y=0.0;
    double x1[10][40]={{0,},},x2[10][40]={{0,},},y1[10][40]={{0,},},y2[10][40]={{0,},},r[10][40]={{0,},};
    double SIN[10]={0.0};
    double rati=0.0;
    cin>>test;
    for(aa=0;aa<test;aa++)
    {
        cin>>eclipsenum;
        for(i=0;i<eclipsenum;i++){
            cin>>x1[aa][i]>>y1[aa][i]>>x2[aa][i]>>y2[aa][i]>>r[aa][i];
        }
    }

    double *rr=(double *)malloc(sizeof(double)*eclipsenum);
    double *yy=(double *)malloc(sizeof(double)*eclipsenum);
    double *H=(double *)malloc(sizeof(double)*eclipsenum);
    double *K=(double *)malloc(sizeof(double)*eclipsenum);
    //H[eclipsenum];
    //K[eclipsenum];
    for(aa=0;aa<test;aa++){
        for(i=0;i< eclipsenum;i++){
            *(rr+i) =pow(r[aa][i],2)/4;
            //cout << "rr:" << *(rr+i) << endl;
            *(yy+i) =rr[i]-pow(y2[aa][i]-y1[aa][i],2)/4-pow(x2[aa][i]-x1[aa][i],2)/4;
            //cout << "yy:" << *(yy+i) << endl;
            *(H+i)=(x1[aa][i]+x2[aa][i])/2;
            //cout << "H:" << *(H+i) << endl;
            *(K+i)=(y1[aa][i]+y2[aa][i])/2;
            //cout << "K:" << *(K+i) << endl;
        }
        for(x=-50;x<50;){
            for(y=-50;y<50;){
                for(i=0;i<eclipsenum;i++){
                    if(pow(x-*(H+i),2.0)/(*(rr+i))+pow((y-*(K+i)),2.0)/(*(yy+i))<1.0){//0.7
                            SIN[aa]+=0.01;
                            break;
                    }
                }//eclipse
                y+=0.1;
            }//y
            x+=0.1;
        }//x
        rati=round(100*(S-SIN[aa])/S);//+0.12
        cout<<rati<< "%" <<endl;
    }//aa
    return 0;
}
double round(double val)
{
    return (val> 0.0) ? floor(val+ 0.5) : ceil(val- 0.5);
}
