#include<iostream>
using namespace std;
void counting_sort(int a[],int b[],int n,int k){
    int c[k+1];
    for(int i=0;i<=k;i++)
        c[i]=0;
    for(int i=0;i<n;i++)
        c[a[i]]++;
    for(int i=1;i<=k;i++)
        c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--){
        c[a[i]]--;
        b[c[a[i]]]=a[i];
        
    }
}
int main(){
    int ar[]={1,3,6,2,7,2,5,1,0,3,6,2,3,4,4,4,4};
    int n=sizeof(ar)/sizeof(ar[0]);
    int b[n],k=0;
    for(int i=0;i<n;i++) k=(ar[i]>k)?ar[i]:k;
    counting_sort(ar,b,n,k);
    for(int i=0;i<n;i++) cout<<b[i]<<" ";
    return 0;
}