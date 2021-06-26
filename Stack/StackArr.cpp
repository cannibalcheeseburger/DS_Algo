#include<iostream>

using namespace std;

class Stack{
    int stack[10];
    const int lim=10;
    int top;
    public:
        Stack(){
            top = -1;
        }
        void push(int val){
            if(top>=lim-1)
                cout<<"\nstack overflow\n";                
            else
                stack[++top]=val;
        }

        int pop(){
            if(top<=-1){
                cout<<"\n stack underflow";
                return -1;}
            else{
                int val = stack[top--];
                return val;}
        }

        int peek(){
            if(top<=-1){
                cout<<"Stack empty";
                return -1;
            }
            return stack[top];
        }

        void print_stack(){
            for(int i =0;i<=top;i++)
                cout<<stack[i]<<"->";
        }

        bool is_empty(){
            if(top<0)
                return true;
            return false;
        }
};


int main(){
    Stack s;
    s.push(2);
    cout<<s.is_empty();
    return 0;
}