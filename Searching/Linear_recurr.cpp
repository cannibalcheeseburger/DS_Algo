#include<iostream>
using namespace std;
int linear(int ar[],int h,int item)
{
    cout<<h<<"\n";
    if(h<0){
        return -1;
    }
    else{
        if(ar[h]==item) return h;
        else linear(ar,h-1,item);
    }
}
int main(){
    int ar[10]={213,23,63,1,37,75,8,63,83,96};
    int item;
    cout<<"enter item";
    cin>>item;
    int i;
    i= linear(ar,9,item);
    cout<<"at position: "<<i;
    return 0;
}