#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter no. of rows";
    cin>>n;
    int A[n][n],B[n][n],C[n][n];
    cout<<"enter elements for 1st Matrix";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
    cout<<"Enter for Second Matrix";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>B[i][j];
        }
    }
    cout<<"\nFirst Matrix:";
    for(int i=0;i<n;i++){
        cout<<"\n";
        for(int j=0;j<n;j++){
            cout<<A[i][j]<<"    ";
        }
    }
    cout<<"\nSecond Matrix:";
    for(int i=0;i<n;i++){
        cout<<"\n";
        for(int j=0;j<n;j++){
            cout<<B[i][j]<<"    ";
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            C[i][j]=0;
            for(int k=0;k<n;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    cout<<"\nMatrix Multiplication:";
    for(int i=0;i<n;i++){
        cout<<"\n";
        for(int j=0;j<n;j++){
            cout<<C[i][j]<<"    ";
        }
    }  
}