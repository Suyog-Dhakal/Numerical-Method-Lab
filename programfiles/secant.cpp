#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    int choice;
    double x,a,b,c,fc,error;
    cout<<"Enter the function you want to use::"<<endl;
    cout<<"1)x^3-3x^2+2x-2\n2)x^2+4x+5\n3)xSin(x)+Cos(x)\n\n\t\t=>";
    cin>>choice;
    if (choice !=1 && choice !=2 && choice !=3)
    {
        cout<<"Invalid choice...";
        return 0;
    }
    cout <<"\n\nPlease, provide two initial guess::";
    cin>>a>>b;
    cout <<"Also, provide the tolerable relative error::";
    cin>>error;
    c=(a*func(b,choice)-b*func(a,choice))/(func(b,choice)-func(a,choice));
    int i=1;
    cout<<endl<<"Iteration "<<i<<":"<<endl;
    cout<<"x("<<i-1<<")"<<"="<<a<<endl;
    cout<<"x("<<i<<")"<<"="<<b<<endl;
    cout<<"x("<<i+1<<")"<<"="<<c<<endl;
    cout<<"fx("<<i+1<<")"<<"="<<func(c,choice)<<endl;
    //cout<<i<<"\t\t"<<a<<"\t"<<b<<"\t\t"<<c<<"\t\t"<<func(c,choice)<<endl;
    while(abs((c-b)/c)>=error)
    {
        a=b;b=c;i++;
        c=(a*func(b,choice)-b*func(a,choice))/(func(b,choice)-func(a,choice));
        cout<<endl<<"Iteration "<<i<<":"<<endl;
        cout<<"x("<<i-1<<")"<<"="<<a<<endl;
        cout<<"x("<<i<<")"<<"="<<b<<endl;
        cout<<"x("<<i+1<<")"<<"="<<c<<endl;
        cout<<"fx("<<i+1<<")"<<"="<<func(c,choice)<<endl;
    }
    cout<<"\n\nThe root with the given tolerable error is "<<c;
    return 0;
}
