#include<iostream>
using namespace std;
void merge(int a[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++){
        L[i]=a[p+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=a[q+1+i];
    }
    int i,j;
    i=j=0;
    int k=p;
    while(i<n1&&j<n2){
        if(L[i]<=R[j])
            a[k]=L[i++];
        else a[k]=R[j++];    
        k++;
    }
    while(i<n1){
        a[k]=L[i];
        k++;
        i++;
    }
    while(j<n2){
        a[k]=R[j];
        k++;
        j++;
    }
}
void merge_sort(int a[],int p,int r){
   
    if(p<r){
        int q=(p+r)/2;
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
}

int main(){
    int a[10]={23,53,2,15,12,25,135,32,33,92};
    merge_sort(a,0,9);
    for(int i=0;i<10;i++) cout<<a[i]<<" ";
    return 0;
}