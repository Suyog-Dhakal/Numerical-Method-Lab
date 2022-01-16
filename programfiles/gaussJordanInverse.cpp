#include<bits/stdc++.h>
#define SIZE 10
using namespace std;

float a[SIZE][SIZE],Ratio;
int i,j,k,n;

void input(int n){
    cout<<"enter coefficients of Matrix: "<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<"a["<<i<<"]["<<j<<"] = ";
            cin>>a[i][j];
        }
    }
    return;
}

void augmented(int n){
    for(i = 1; i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j){
                a[i][j+n] = 1;
            }else{
                a[i][j+n] = 0;
            }
        }
    }
    return;
}

void calculation(int n){
    for(i=1;i<=n;i++){
        if(a[i][i] == 0.0){
            cout<<"error"<<endl;
            return;
        }
        for(j=1;j<=n;j++){
            if(i!=j){
                Ratio = a[j][i]/a[i][i];
                for(k=1;k<=2*n;k++){
                    a[j][k] = a[j][k] - Ratio*a[i][k];
                }

            }
        }
    }
    //row operation to make diagonal element to 1
    for(i=1;i<=n;i++){
        for(j=n+1;j<=2*n;j++){
            a[i][j] = a[i][j]/a[i][i];
        }

    }
    return;
}

void display(int n){
    cout<<endl<<"the inverse of matrix is"<<endl;
    for(i=1;i<=n;i++){
        for(j=n+1;j<=2*n;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    return;
}

int main(){
    //cout<<setprecision(3)<<fixed;
    cout<<"enter order of matrix";
    cin>>n;
    input(n);
    augmented(n);
    calculation(n);
    display(n);
    return 0;
}


