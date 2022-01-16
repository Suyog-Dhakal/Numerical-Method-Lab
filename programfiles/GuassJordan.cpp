#include<bits/stdc++.h>
using namespace std;

class GaussJordan {
private:
    float a[10][10], x[10];
    int n;
public:
    void input();
    void display();
    void calculate();
    bool checkError();
    void finalresult();
};

void GaussJordan::input(){
    cout<<"Enter the number of unknowns: "; cin>>n;
    cout<<"Enter the coefficient: "<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++){
            cout<<"a["<<i<<"]["<<j<<"] = ";
            cin>>a[i][j];
        }
    }
    return;
}

void GaussJordan::display(){
    for(int i=1;i<=n;i++){

        for(int j=1;j<=n+1;j++){

            if(j == n+1){
                cout<<":\t "<<a[i][j];
            }
            else{
                cout<<a[i][j]<<'\t';
            }

        }
        cout<<endl;
    }
    return;
}

bool GaussJordan::checkError(){
    for(int j=1; j<=n; j++){
        if(a[j][j] == 0)
            return true;
        return false;
    }
}

void GaussJordan::calculate(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i != j){
                float res = a[j][i]/a[i][i];
                for(int k=1;k<=n+1;k++){
                    a[j][k] = a[j][k] - res* a[i][k];
                }
            }
        }
    }
    return;
}

void GaussJordan::finalresult(){
    cout<<endl<<"the required result is: "<<endl;
    for(int i=1; i<=n;i++){
        x[i] = a[i][n+1]/a[i][i];
        cout<<"x["<<i<<"] = "<<x[i]<<endl;
    }
    return;
}

int main(){

    GaussJordan gj;

        gj.input();
        cout<<endl<<"The augmented matrix is: "<<endl;
        gj.display();
        bool error = gj.checkError();
        if(error == true){
            cout<<"the system of linear equations cannot be solved"<<endl;
            return 0;
        }

        gj.calculate();
        cout<<"The augmented matrix is :"<<endl;
        gj.display();
        gj.finalresult();

    return 0;

}
