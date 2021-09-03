#include<iostream>
using namespace std;

#define lim 5

class Queue{
    int queue[lim];

    public:
        int front;
    int rear;
        Queue(){
            front = -1;
            rear = -1;
        }

        void enqueue(int data){
            if(front==-1 && rear==-1){
                front=0;
                rear =0;
                queue[rear]=data;
            }
            else if(is_full())
                cout<<"\nQueue Overflow";
            else{
                rear = (rear+1)%lim;
                queue[rear]=data;
                }
        }

        void dequeue(){
            if(is_empty())
                cout<<"\nQueue Underflow";
            else if(front==rear)
                front=rear=-1;
            else
                front = (front+1)%lim;
        }

        int peek(){
            return queue[front];
        }

        bool is_full(){
            if((rear+1)%lim==front)
                return true;
            return false;
        }

        bool is_empty(){
            if(front ==-1)
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

    q.dequeue();
    q.dequeue();
    
       q.enqueue(6);
    q.enqueue(7);
while(!q.is_empty()){
    cout<<q.peek()<<"->";
    q.dequeue();
}
    return 0;
}