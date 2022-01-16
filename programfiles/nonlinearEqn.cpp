#include<iostream>
#include<cmath>

using namespace std;

float function(float x){
    return (pow(x,3)-7);
}

int main() {
    float a,b,c=0,E;
    cout<<"equation used is x^3-7 \n";
    cout<<"Enter initial interval (a,b) \n";
    cout<<"enter a=";
    cin>> a;
    cout<<"\n enter b=";
    cin>> b;
    cout<<"\nenter tolerance in error:  "
    cin>>E;

    if(function(a)*function(b) > 0){
        cout<<"Real root doesnot exist.\n";
    }

    while(abs(function(c)) > E){
        c = (a+b)/2;
        function(c)*function(a) < 0 ? b=c : a=c; 
    }

    cout<<"root of the equation is "<<c;
}