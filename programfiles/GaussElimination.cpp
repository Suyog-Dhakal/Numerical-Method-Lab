
#include<bits/stdc++.h>
#define SIZE 10
using namespace std;

float a[SIZE][SIZE], x[SIZE],Ratio;
int i,j,k,n;

void input(int n){
    cout<<"enter coefficients of Augmented Matrix: "<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n+1;j++){
            cout<<"a["<<i<<"]["<<j<<"] = ";
            cin>>a[i][j];
        }
    }
    return;
}

void calculation(int n){
    for(i=1;i<=n-1;i++){
        if(a[i][i] == 0.0){
            cout<<"error"<<endl;
            return;
        }
        for(j=i+1;j<=n;j++){
            Ratio = a[j][i]/a[i][i];
            for(k=1;k<=n+1;k++){
                a[j][k] = a[j][k] - Ratio*a[i][k];
            }
        }
    }

    //obtaining solution by back substitution method
    x[n] = a[n][n+1]/a[n][n];

    for(i=n-1;i>=1;i--){
        x[i] = a[i][n+1];
        for(j=i+1;j<=n;j++){
            x[i] = x[i] - a[i][j]*x[j];
        }
        x[i] = x[i]/a[i][i];
    }
    return;
}

void display(int n){
    cout<<"solution of the equation is"<<endl;
    for(i=1;i<=n;i++){
        cout<<"x["<<i<<"] = "<<x[i]<<endl;
    }
    return;
}

int main()
{
    cout<<"Enter the number of unknowns: ";cin>>n;
    input(n);
    calculation(n);
    display(n);
    return 0;
}
