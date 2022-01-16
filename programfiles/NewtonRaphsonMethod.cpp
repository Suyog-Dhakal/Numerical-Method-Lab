
#include <iostream>
#include <math.h>
using namespace std;
float fn(float x)
{
     //return  pow(x,2)+(3*x)+1 ;
     return ( x*sin(x) + cos(x) );
}
float de(float x)
{
     return ( x*cos(x));
}
int main()
{   float a,e=0,z,tol;
cout<<"function xsin(x) + cos(x) "<<endl;
    cout<<"Enter initial guess: ";
    cin>>a;
    cout<<"enter tolerance error: ";
    cin>>tol;
    do
    {   e++;
        z=a-(fn(a)/de(a));
        cout<<"The iterative "<<e<<" root is "<<z;
        a=z;
        cout<<endl;
    }while(abs(fn(z))>tol);
    return 0;
}
