#include<iostream>
#include<stack>
#include <algorithm>

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
    return 0;

}

string InPost(string str){
    stack<char> s;
    string res="";
    str = '('+str+')';
    int len = str.length();

    for(int i = 0;i<len;i++){
        char c = str[i];
        if(is_operand(c))
            res+=c;
        else if(c=='(')
            s.push('(');
        else if(c==')'){
            while(s.top()!='(' ){
                res+=s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && prec(c)<=prec(s.top())){
                res+=s.top();
                s.pop();
            }
            s.push(c);
        }

    }
    while(!s.empty()){
        res+=s.top();
        s.pop();
    }
    return res;
}

string InPre(string s){
    reverse(s.begin(),s.end());
    for(int i =0;i<s.size();i++){
        if(s[i]==')'){
            s[i]='(';i++;}
        else if(s[i]=='('){
            s[i]=')';i++;}
    }
    string result = InPost(s);
    reverse(result.begin(),result.end());
    return result;
}

int main(){

    string s;
    s = "A+B*C";
    cout<<InPre(s);
    return 0;
}