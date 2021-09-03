#include<iostream>
#include<stack>

using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;
    public:
        void enqueue(int data){
            s1.push(data);
        }
        int dequeue(){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int dat = s2.top();
            s2.pop();
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            return dat;
        }
       
        bool empty(){
            return s1.empty();
        }


    
};

int main(){
    Queue q;
    q.enqueue(2);
    q.enqueue(1);
    q.dequeue();
        q.enqueue(2);
    q.enqueue(1);
    while(!q.empty())
        cout<<q.dequeue()<<"->";
    return 0;
}