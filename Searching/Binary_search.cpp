#include<iostream>
using namespace std;
int main(){
    int ar[10]={5,14,27,38,49,52,69,76,82,94};
    int item,l,h,mid,index=-1;
    l=0; h=9;
    cin>>item;
    while(l<=h){
        mid=(l+h)/2;
        if(ar[mid]==item) {
            index=mid; 
            break;
        }
        else if(ar[mid]<item) l = mid+1;
        else h = mid-1;
    
    }
    cout<<"Position of item is : "<<index;
    return 0;
}