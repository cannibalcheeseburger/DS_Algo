#include<iostream>
using namespace std;
#define LEFT(i) 2*i+1;
#define RIGHT(i)  2*i+2;
void max_heapify(int a[],int i,int size){
    int l= LEFT(i);
    int r= RIGHT(i);
    int large = i;
    if(l<size && a[l]>a[large]){
        large = l;
    }
    if(r<size && a[r]>a[large]){
        large = r;
    }
    int temp;
    if(large!=i){
        temp = a[i];
        a[i] = a[large];
        a[large] = temp;
        max_heapify(a,large,size);
    }
}    
void build_heap(int a[],int size){
    for(int i=(size/2)-1;i>=0;i--){
        max_heapify(a,i,size);
    }
}  
int main(){
    int ar[]={27,17,3,16,13,10,1,5,7,12,4,8,9,0,76};
    int size = sizeof(ar)/sizeof(ar[0]);
    build_heap(ar,size);
    for(int i=0;i<size;i++) cout<<ar[i]<<" ";
    return 0;
}