//a little different value.. added  0 in the mix
#include<iostream>
using namespace std;
#define LEFT(i) 2*i+1;
#define RIGHT(i) 2*i+2;
#define PARENT(i) (i-1)/2;
void heapify(int a[],int i,int size){
    int large =i;
    int l = LEFT(i);
    int r = RIGHT(i);
    if(l<size && a[l]>a[large])
        large = l;
    if(r<size && a[r]>a[large])
        large = r;
    if(large!= i){
        swap(a[large],a[i]);
        heapify(a,large,size);
    }        
}
void node_delete(int a[],int &size){
    swap(a[0],a[size-1]);
    size--;
    heapify(a,0,size);
}
int main(){
    int a[20] = {76 ,17 ,27, 16, 13, 10, 3, 5, 7, 12, 4, 8, 9, 0, 1 };
    int size  = 16;
    char ch = 'y';
    while(ch=='y'){
        node_delete(a,size);
        for(int i=0;i<size;i++) cout<<a[i]<<" ";
        cout<<"more?(y/n)";
        cin>>ch;
    }
    return 0;
}