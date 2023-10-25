#include<iostream>
#define PARENT(x) int(x/2)
#define LEFT(x) 2*x +1
#define RIGHT(x) 2*x +2
using namespace std;
const int num = 10;

class Heap{
    public:
    int arr[num];
    int last;

    Heap(){
        last = 0;
    }

    Heap(int* a,int n){
        last = 0;
        for(int i =0;i<n;i++,last++) arr[i]=a[i];
        for(int i =last/2-1;i>=0;i--){
            heapify(i);
        }
        
    }

    void insert(int i){
        if(last==0)
            return;
        if(arr[PARENT(i)]<arr[i]){
            swap(arr[i],arr[PARENT(i)]);
            insert(PARENT(i));
        }
    }

    void heapify(int i ){
        int r = RIGHT(i);
        int l = LEFT(i);
        int largest = i;
        if(l<last && arr[l]>arr[largest]){
            largest = l;
        }
        if(r<last && arr[r]>arr[largest]){
            largest = r;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(largest);
        }
    }


    void print(){
        for(int i =0;i<last;i++){
            cout<<arr[i]<<" ";
        }
    }

    void heapsort(){
        int index = last-1;
        for(int i =0;i<last;i++){
            cout<<arr[0]<<" ";
            arr[0] = arr[--last];
            heapify(arr[last-1]);
            
        }
    }

};

int main(){
    const int n=5;
    int arr[n]={10,20,15,30,40};
    Heap heap(arr,n);
    //heap.print();
    heap.heapsort();
    return 0;
}