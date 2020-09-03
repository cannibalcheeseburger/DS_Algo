#include<iostream>
using namespace std;
#define LEFT(i) 2*i+1;
#define RIGHT(i) 2*i+2;
#define PARENT(i) (i-1)/2;
void heapify(int a[],int i,int size){
    int l = LEFT(i);
    int r = RIGHT(i);
    int large = i;
    if(l<size && a[l]>a[large])
        large = l;
    if(r<size && a[r]>a[large])
        large = r;
    if(large!=i){
        swap(a[large],a[i]);
        heapify(a,large,size);
    }        
}
void build_max_heap(int a[],int size){
    for(int i=(size/2)-1;i>=0;i--){
        heapify(a,i,size);
    }
}
void heapsort(int a[],int size){
    build_max_heap(a,size);
    for(int i=size-1;i>0;i--){
        swap(a[i],a[0]);
        size--;
        heapify(a,0,size);
    }
}
int main(){
    int a[20]={2,7,3,86,35,64,56,23,75,37,25,12,53,73,226,34};
    int size = 16;
    heapsort(a,size);
    for(int i=0;i<size;i++) cout<<a[i]<<" ";
    return 0; 
}