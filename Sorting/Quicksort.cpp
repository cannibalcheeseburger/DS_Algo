#include<iostream>
using namespace std;
int partition(int a[],int p,int r){
    int start = p;
    int end = r;
    int pivot = a[p];
    while(start<end){
        while(a[start]<=pivot) start++;
        while(a[end]>pivot) end--;
        if(start<end) swap(a[start],a[end]);
    }
    swap(a[end],a[p]);
    return end;
}
void quicksort(int a[],int p,int r){
    if(p<r){
        int q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
int main(){
    int a[]={2,35,7,3,633,74,33,26,86,64,253};
    int n=sizeof(a)/sizeof(a[0]);
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}