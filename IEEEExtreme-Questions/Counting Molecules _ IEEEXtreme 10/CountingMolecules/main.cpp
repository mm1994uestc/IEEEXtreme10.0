#include <iostream>
using namespace std;

int main()
{
    int C=0,H=0,O=0;
    double Num_W=0.0,Num_C=0.0,Num_G=0.0;
    cin >> C >> H >> O;

    Num_W=(2*O+H-4*C)/4;
    Num_C=(2*O-H)/4;
    Num_G=(4*C-2*O+H)/24;

    if(Num_W<0 || Num_C<0 || Num_G<0) { cout << "Error" << endl; return 0;}
    if(Num_W!=(int)Num_W || Num_C!=(int)Num_C || Num_G!=(int)Num_G) {cout << "Error" << endl; return 0;}
    cout << (int)Num_W << " " << (int)Num_C << " " << (int)Num_G << endl;
    return 0;
}
