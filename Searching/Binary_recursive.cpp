#include<iostream>
using namespace std;
int binary_recursive(int ar[],int l,int n,int item){
    
    if(l<=n){
        int mid=(n+l)/2;
        if(item==ar[mid]) return mid;
        else if(item<ar[mid]) 
             binary_recursive(ar,l,mid-1,item);
        else binary_recursive(ar,mid+1,n,item);    
    }
    else return -1;
}
int main(){
    int ar[10]={5,14,27,38,49,52,69,76,82,94};
    int n=10;
    int item,index;
    cin>>item;
    index=binary_recursive(ar,0,n,item);
    if(index>=0) cout<<"Item at position:"<<index+1;
    else cout<<"Not found";
    return 0;
}