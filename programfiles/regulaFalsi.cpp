
#include <bits/stdc++.h>

using namespace std;

double a,b,c,fa,fb,fc,error;
int i,choice;
double func(double x,int choice)
{
    double fx;
    switch (choice)
    {
        case 1:
            fx=(pow(x,3)-3*pow(x,2)+2*x-2);
            break;
        case 2:
            fx=(pow(x,2)+4*x+5);
            break;
        case 3:
            fx=x*sin(x)+cos(x);
            break;
    }
    return fx;
}

void input(){


    cout <<"Enter tolerable relative error:";
    cin>>error;
    cout<<"\n enter two initial guess::"<<endl;
    do
    {
        cout<<"initital guess (a,b) =>";cin>>a>>b;
        fa=func(a,choice);
        fb=func(b,choice);
    }while (fa*fb>0);
}

void calculation()
{
    i=1;
    do
    {
        c=(a*fb-b*fa)/(fb-fa);
        fc=func(c,choice);
        cout<<endl<<"Iteration "<<i<<":"<<endl;
        cout<<"x("<<i-1<<")"<<"="<<a<<endl;
        cout<<"x("<<i<<")"<<"="<<b<<endl;
        cout<<"x("<<i+1<<")"<<"="<<c<<endl;
        cout<<"fx("<<i+1<<")"<<"="<<fc<<endl;
        if(fc*fa>0)
            a=c;
        else
            b=c;
        fa=func(a,choice);
        fb=func(b,choice);
        i++;
    }while(abs(fc)>=error);
    cout<<"the root is :"<<c;
}

int main()
{
    int choice;
    cout<<"Enter the function you want to use::"<<endl;
    cout<<"1)x^3-3x^2+2x-2\n2)x^2+4x+5\n3)xSin(x)+Cos(x)\n\n\t\t=>";
    cin>>choice;
    if (choice !=1 && choice !=2 && choice !=3)
    {
        cout<<"Invalid choice...";
        return 0;
    }
    input();
    calculation();



}
