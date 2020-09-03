#include<iostream>
using namespace std;
int main(){
    int i,j,key;
    int a[10]={56,7,4,23,75,35,45,87,36,2};
    for(j=1; j<10;j++){
        key=a[j];
        i=j-1;
        while(i>=0 && a[i]> key){
            a[i+1]=a[i];
            i--;
        }     
        a[i+1]=key;   
    }
    for(i=0;i<10;i++) cout<<a[i]<<" ";
    return 0;
