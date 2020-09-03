#include<iostream>
using namespace std;
#define LEFT(i) 2*i+1;
#define RIGHT(i) 2*i+2;
#define PARENT(i) i/2;
void heapify(int a[],int count){
    int parent = PARENT(count);
    if(a[parent]>0){
        if(a[count]>a[parent]){
            swap(a[parent],a[count]);
            heapify(a,parent);
        }
    }
}
void node_insert(int a[],int& count,int key){
    a[count]=key;
    
    if(count>0) heapify(a,count);
    count++;
}
int main(){
    int a[20],key,count =0;
    char ch;
    do{
        cout<<"Enter Node:";
        cin>>key;
        node_insert(a,count,key);
        cout<<"more?(y/n)";
        cin>>ch;
    } while(ch=='y'||ch=='Y');
    for(int i=0;i<count;i++) cout<<a[i]<<" ";

}