#include<iostream>
#include<stack>
using namespace std;

const char operands[7] = {'(',')','^','/','*','+','-'};


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
    stack<char> s;
    int len = str.length();
    for(int i = 0;i<len;i++){

        char c = str[i];
        
        if(is_operand(c))
            cout<<c;
        else if(c=='(')
            s.push('(');
        else if(c==')'){
            while(s.top()!='(' ){
                cout<<s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && prec(c)<=prec(s.top())){
                cout<<s.top();
                s.pop();
            }
            s.push(c);
        }

    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }

}
int main(){

    string s;
    s = "a+b*(c^d-e)^(f+g*h)-i";
    InPost(s);
    return 0;
}