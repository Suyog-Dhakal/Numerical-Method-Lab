#include<iostream>
using namespace std;

class Dolittle{
private:
    int n;
    float a[10][10],b[10],l[10][10],u[10][10],y[10];
public:
    void input();
    void inputDisplay();
    void factorization();
    void calculation();

};

void Dolittle::input(){
    cout<<"enter the numbers of unknowns: ";cin>>n;
    cout<<"enter the coefficients: "<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++){
            if(j==n+1){
                cout<<"b["<<i<<"] =";
                cin>>b[i];
            }else{
                cout<<"a["<<i<<"]["<<j<<"]=";
                cin>>a[i][j];
            }
        }
    }
    return;
}
void Dolittle::inputDisplay(){
    cout<<"the input is"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n+1;j++){
            if(j==n+1)
                cout<<":\t"<<b[i];
            else
                cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }

    return;
}
void Dolittle::factorization(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>j){
                float sum=0;
                for(int k=1;k<j;k++){
                    sum += l[i][k]*u[k][j];
                }
                l[i][j] = (a[i][j]-sum)/u[j][j];
                u[i][j]=0;
            }
            else{
                float sum=0;
                for(int k=1;k<i;k++){
                    sum+=l[i][k]*u[k][j];
                }
                u[i][j] = a[i][j]-sum;
                if(i==j)
                    l[i][j]=1;
                else
                    l[i][j]=0;
            }
        }
    }
    cout<<"the L matrix is:\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<l[i][j]<<"\t";
        cout<<endl;
    }
    cout<<"the U matrix is:\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<u[i][j]<<"\t";
        cout<<endl;
    }
    return;
}

void Dolittle::calculation(){
    for(int i=1;i<=n;i++){
        float sum=0;
        for(int j=1;j<i;j++){
            sum+=l[i][j]*b[j];
        }
        b[i] = (b[i]-sum);
    }
    for(int i=n;i>=1;i--){
        float sum=0;
        for(int k=n;k>i;k--){
            sum+=u[i][k]*b[k];
        }
        b[i] = (b[i]-sum)/u[i][i];
    }

    cout<<"the final result is:\n";
    for(int i=1;i<=n;i++)
        cout<<b[i]<<endl;
    return;
}

int main()
{
    Dolittle factor;
    factor.input();
    factor.inputDisplay();
    factor.factorization();
    factor.calculation();

}
