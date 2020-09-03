#include<iostream>
using namespace std;
int main(){
    int temp;
    int a[10]={12,125,31,42,212,4,1,74,53,37};
    int n=10;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
