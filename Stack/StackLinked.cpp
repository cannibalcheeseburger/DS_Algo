#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        next = NULL;
    }  
    
};
class Stack{
    Node *Top;
    public:

        Stack(){
            Top = NULL;
        }

        void push(int val){
            Node* newptr = new Node();
            newptr->data = val;
            if(!Top){
                Top = newptr;
                return;
            }
            newptr->next = Top;
            Top = newptr;
        }

        int pop(){
            if(is_empty())
                return -1;
            Node*ptr = Top;
            int data = Top->data;
            Top = Top->next;
            delete ptr;
            return data;
        }

        int peek(){
        if(!Top){
            cout<<"Empty Stack";
            return -1;
        }
        return Top->data;
        }

        bool is_empty(){
            if(!Top)
                return true;
            return false;
        }
};


int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.is_empty()){
        cout<<s.pop()<<"->";
    }
    if(s.is_empty())
        cout<<"\nEmpty";
    else cout<<"\nNot Empty";
    return 0;
}