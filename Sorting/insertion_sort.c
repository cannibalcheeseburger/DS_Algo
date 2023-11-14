#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b=temp;
}

void insertion_sort(int *arr,int size){
    for(int top=2;top<size;top++){
        for(int i=top;i>0;i--){
            if(arr[i]<arr[i-1])
                swap(&arr[i],&arr[i-1]);
            else
                break;
        }
    }
}

int main(){
    int arr[10]={2,6,26,1,9,5,7,3,4,18};
    insertion_sort(arr,10);
    for(int i=0;i<10;i++)
    printf(" %d",arr[i]);
    return 0;
}