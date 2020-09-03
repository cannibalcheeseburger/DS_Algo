#include<iostream>
#include<math.h>
using namespace std;
void count_sort(int a[],int n,int k,int exp){
    int c[k+1],b[n];
    for(int i=0;i<k+1;i++)  
        c[i]=0;
    for(int i=0;i<n;i++)
        ++c[(a[i]/exp)%10];
    for(int i=1;i<k+1;i++)
        c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--){
        c[(a[i]/exp)%10]--;
        b[c[(a[i]/exp)%10]]=a[i];
    }
    for(int i=0;i<n;i++) a[i]=b[i];
}
void radix_sort(int a[],int n,int k){
    for(int exp=1;k/exp;exp*=10)
        count_sort(a,n,k,exp);
}
int main(){
    int ar[]={364,24,57,9,84,5,843,2,26,924,296,16,35,436};
    int n = sizeof(ar)/sizeof(ar[0]);
    int k;
    for(int i=0;i<n;i++) k=(ar[i]>k)?ar[i]:k; 
    radix_sort(ar,n,k);
    for(int i=0;i<n;i++) cout<<ar[i]<<" ";
    return 0;   
}