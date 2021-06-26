#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(){
            next = NULL;
        }
};

class LinkedList{
    public:
    Node  *Head;
    LinkedList(){
        Head = NULL;
        Head = new Node();
    }

    void printlist(){
        Node *ptr = Head->next;
        while(ptr!=NULL){
            cout<<ptr->data<<"->";
            ptr = ptr->next;
        }
    }

    void pushHead(int data){
        //add node
        Node *newptr = new Node();
        newptr->data = data;
        newptr->next = Head->next;
        Head->next = newptr;
    }

    void popHead(){
        //delete
        Node *next = Head->next;
        Head->next = next->next;
        delete next;
    }

    void pushTail(int data){
        Node *ptr=Head;
        Node *newptr = new Node();
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        newptr->data = data;
        ptr->next = newptr;

    }


    void popTail(){
        Node *ptr=Head;
        Node *newptr = ptr->next;
        while(newptr->next!=NULL){
            ptr = ptr->next;
            newptr = newptr->next;
        }
        ptr->next = NULL;
        delete newptr;

    }

    void popKey(int key){
        Node *ptr = Head;
        Node *nextptr = ptr->next;
        while(nextptr!=NULL){
            if(nextptr->data ==key){
                ptr->next = nextptr->next;
                delete nextptr;
                return;
            }
            ptr=ptr->next;
            nextptr = nextptr->next;
        }
        cout<<"\nNot Found\n";
    }

    void reverse(){
        if(!Head) return;
        Node *prev = Head->next;
        if(!prev->next) return;
        Node *ptr = prev->next;
        if(!ptr->next) return;
        Node *next = ptr->next;
        
        while(next!=NULL){
            if(prev == Head->next)
                prev->next  = NULL;

            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        Head->next = prev;
    }

};



int main(){
    
    LinkedList ll;
    int ch=1;
    ll.pushHead(2);
    ll.pushHead(1);

/*
    do{
        cout<<"\n1.PushHead\n2.PopHead\n3.PushTail(O(n))\n4.PopTail\n5.PopKey\n6.Reverse\n0.Exit";
        cin>>ch;
        switch(ch){
            case 1:{
                int data;
                cout<<"Enter Data:";
                cin>> data;
                ll.pushHead(data);
                break;
            }
            case 2:{
                ll.popHead();
                break;
            }
            case 3:{
                int data;
                cout<<"Enter Data:";
                cin>> data;
                ll.pushTail(data);
                break;
            }
            case 4:{
                ll.popTail();
                break;
            }
            case 5:{cout<<"\nEnter Key";
                int key;
                cin>>key;
                ll.popKey(key);
                break;
            }
            case 6:{
                ll.reverse();
                break;
            }
        }
        cout<<"\nList:\n";
        ll.printlist();

    }while(ch);
*/  ll.reverse();
    ll.printlist();
    return 0;    

}