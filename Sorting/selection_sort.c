#include<stdio.h>
#include<stdlib.h>

#define N 10

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selection_sort(int arr[]){
    int min;
    for(int i=0; i<(N-1) ;i++){
        min = i;
        for(int j=i+1; j<N ;j++){
            if(arr[j]<arr[min])
                min = j;
        }
        swap(&arr[i],&arr[min]);
    }
    return;
}

int minimum(int *arr,int j,int min){
    if(j>N-1)
        return min;
    if(arr[j]<arr[min])
        min = j;    
    return minimum(arr,j+1,min);
}

void selection_sort_rec(int *arr){
    
    for(int i=0;i<N-1;i++){
        swap(&arr[i],&arr[minimum(arr,i+1,i)]);
    }
    return;
}

int main(){
    int arr[N]={6,1,71,23,72,35,8,3,22,42};
    selection_sort_rec(arr);
    for(int i=0;i<N;i++) printf("%d ",arr[i]);
}