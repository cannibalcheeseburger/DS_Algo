#include<iostream>
#include<string>

using namespace std;

const char operands[7] = {'(',')','^','/','*','+','-'};

class Node{
    public:
    char data;
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

        char pop(){
            if(is_empty())
                return '-';
            Node*ptr = Top;
            char data = Top->data;
            Top = Top->next;
            delete ptr;
            return data;
        }

        char peek(){
        if(!Top){
            cout<<"Empty Stack";
            return '0';
        }
        return Top->data;
        }

        bool is_empty(){
            if(!Top)
                return true;
            return false;
        }
};

bool is_operand(char c){
    for(int i = 0;i<7;i++)
        if(::operands[i]==c)
            return false;
    return true;

}

int prec(char c){
    if(c=='^')
        return 3;
    if(c=='/' || c=='*')
        return 2;
    if(c=='+' || c=='-')
        return 1;
    return -1;

}

void InPost(string str){
    Stack s;
    int len = str.length();
    for(int i = 0;i<len;i++){

        char c = str[i];
        
        if(is_operand(c))
            cout<<c;
        else if(c=='(')
            s.push('(');
        else if(c==')'){
            while(s.peek()!='(' || s.is_empty()){
                cout<<s.pop();
            }
            s.pop();
        }
        else{
            while(!s.is_empty() && prec(c)<=prec(s.peek())){
                cout<<s.pop();
            }
            s.push(c);
        }

    }
    while(!s.is_empty())
        cout<<s.pop();

}
int main(){

    string s;
    s = "a+b*(c^d-e)^(f+g*h)";
    InPost(s);
    return 0;
}