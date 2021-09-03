#include<iostream>
using namespace std;

#define lim 10

class Queue{
    int queue[lim];
    int front;
    int rear;
    public:
        Queue(){
            front = 0;
            rear = -1;
        }

        void enqueue(int data){
            if(is_full())
                cout<<"Queue Overflow";
            else
                queue[++rear]=data;
        }

        void dequeue(){
            if(is_empty())
                cout<<"Queue Underflow";
            else
                ++front;
        }

        int peek(){
            return queue[front];
        }

        bool is_full(){
            if(rear>=lim-1)
                return true;
            return false;
        }

        bool is_empty(){
            if(front>rear || front>lim)
                return true;
            return false;
        }

};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    while(!q.is_empty()){
        cout<<q.peek()<<"->";
        q.dequeue();
    }
    return 0;
}