#include<stack>
#include<iostream>
using namespace std;

const char operands[7] = {'(',')','^','/','*','+','-'};

int prec(char c){
    if(c=='^')
        return 3;
    if(c=='/' || c=='*')
        return 2;
    if(c=='+' || c=='-')
        return 1;
    return -1;

}

bool is_operand(char c){
    for(int i = 0;i<7;i++)
        if(::operands[i]==c)
            return false;
    return true;

}

double calc(int a,int b,char c){
    switch (c)
    {
    case '+':return a+b;
    case '-': return a-b;
    case '*':return a*b;
    case '/':return a/b;
    }
    return -1;
}

int eval(string str){
    stack<double> s;
    for(int i = str.size()-1;i>-1;i--){
        if (str[i] == ' ')
            continue;
        if(is_operand(str[i]))
            s.push((str[i])-'0');
        else{
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();
            s.push(calc(a,b,str[i]));
        }
    }
    return s.top();
}

int main(){
    string str = "+ 9 * 12 6";
    cout<<eval(str);
    return 0;
}