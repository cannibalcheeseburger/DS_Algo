#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *next;
};

void printLinkedList(struct node **head){
    struct node *ptr=*head;
    while(ptr){
        printf("%d->",ptr->val);
        ptr=ptr->next;
    }
    printf("NULL\n");

}


int deleteItem(int val,struct node**head){
    struct node *ptr=*head;
    
    if(ptr->val==val){
        *head=ptr->next;
        free(ptr);
        return val;
    }

    struct node *nextptr=ptr->next;

    while(nextptr){

        if(nextptr->val==val){
            ptr->next=nextptr->next;
            free(nextptr);
            return val;
        }
        ptr=nextptr;
        nextptr=nextptr->next;
    }
    return -1;
}

int addItem(int val,struct node **head){

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;
    
    if(*head==NULL){
        *head=newNode;
        return val;
    }

    struct node *ptr=*head;
    while(ptr->next)
        ptr = ptr->next;
    
    ptr->next=newNode;
    return val;
}

int len(struct node *head){
    struct node *ptr = head;
    int count = 0;
    while(ptr){
        ptr = ptr->next;
        count++;
    }
    return count;
}   

void rev(struct node **head){
    if(!*head || (*head)->next==NULL ) return;
    struct node *next,*prev=NULL, *ptr=*head;
    next = ptr->next;
    while(next){      
        ptr->next = prev;    
        prev = ptr;
        ptr = next;
        next = next->next;
    }
    ptr->next= prev;
    *head = ptr;
}

void addLink(int index,struct node *head){
    struct node *temp=head,*ptr = head;
    int i =0;
    while(temp && i<=index)
        {temp=temp->next;i++;}   
     
    while(ptr->next)
        ptr=ptr->next;
    ptr->next=temp;
}

void cycle(struct node* head){
    struct node *slow=head,*fast=head;
    while(fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) {printf("yas kween");return;}
    }
    printf("NOO KWEEN");
}

int main(){
    struct node *head=NULL;
    addItem(3,&head);
    addItem(5,&head);
    addItem(8,&head);
    printLinkedList(&head);
    addItem(12,&head);
   // addLink(1,head);
    cycle(head);
    return 0;
    }