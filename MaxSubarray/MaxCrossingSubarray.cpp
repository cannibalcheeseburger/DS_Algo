#include<iostream>
#include<climits>
using namespace std;
void max_crossing(int a[],int low,int mid, int high){
    int sum=0;
    int left_sum= INT_MIN;   
    int max_left;
    for(int i=mid;i>=0;i--){
        sum+=a[i];
        if(left_sum<sum){
            max_left=i;
            left_sum=sum; 
        }
    }
    int max_right;
    sum=0;
    int right_sum=INT_MIN;
    for(int i=mid+1;i<high;i++){
        sum+=a[i];
        if(sum>right_sum){
            max_right = i;
            right_sum= sum;
        }
    }    
    
    for(int i = max_left;i<=max_right;i++){
        cout<<a[i]<<" ";
    }    
    cout<<"\nmax sum ="<<left_sum+right_sum;
}
int main(){
    int a[10]={-12,523,-263,1,37,8,23,-46,73,-93};
    int low = 0;
    int high =10;
    int mid = (low+high)/2;
    max_crossing(a,low,mid,high);
}