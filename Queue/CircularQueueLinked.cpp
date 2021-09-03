#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
};

class Queue{
    Node* front;
    Node* rear;
    public:
        Queue(){
            front = NULL;
            rear = NULL;
        }

        void enqueue(int data){
            Node *newptr = new Node();
            newptr->data = data;
            if(!rear){
                rear = newptr;
                front = newptr;
                rear->next = front;
                return;
                }
            rear->next = newptr;
            rear = newptr;
            rear->next = front;
        }

        void dequeue(){
            if(is_empty())
                cout<<"Queue Underflow";
            else if(rear==front){
                rear=front=NULL;
            }
            else{
                Node *ptr = front;
                front = front->next;
                rear->next = front;
                delete ptr;
                }
        }

        int peek(){
            return front->data;
        }

        bool is_empty(){
            if(!front || !rear)
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
            q.dequeue();

    return 0;
}