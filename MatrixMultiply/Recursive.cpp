#include<iostream>
using namespace std;
const int n=3;
int MAX=n;
int A[n][n],B[n][n];
int C[n];
void RecursiveMultiply(int n,int i_low,int i_max,int j_low, int j_high){
    if(n==1){
        C[i_low][j_high]=A[i_low][j_low]*B[i_low][j_low];
    }
    else{
        
    }
}
int main(){
    RecursiveMultiply(n,0,n,0,n);
    return 0;
}