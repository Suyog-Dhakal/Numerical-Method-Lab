#include<iostream>
#include<cmath>
using namespace std;
float function(float x){
return (pow(x,3)-7);}
int main()
{
    float a,b,c=0,E;
    cout<<"equation used is x^3-7 \n";
    cout<<"Enter initial interval (a,b) \n";
    cout<<"enter a=";
    cin>>a;
    cout<<"Enter b=";
    cin>>b;
    cout<<"enter tolerance in error:";
    cin>>E;
    if(function(a)*function(c)>E){
        c=(a+b)/2;
        function(c)*function(a) < 0 ? b=c : a=c;

    }
    cout<<"root of the equation is"<<c;


}
