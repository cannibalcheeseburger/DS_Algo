#include<stdio.h>
#include<stdlib.h>

#define M 10

struct node {
    int key;
    int value;
    struct node *next;    
};

struct hashtable{
    struct node *head[M];
};

struct hashtable ht;

void init(){
    for(int i =0;i<M;i++){
        ht.head[i]=NULL;
    }
}

int calc_hash(int key){
    return key%M;
}

void add_node(int key,int value){
    int hash = calc_hash(key);
    struct node *newptr = (struct node *)malloc(sizeof(struct node));
    newptr->key = key;
    newptr->value = value;
    struct node *ptr = ht.head[hash];
    ht.head[hash] = newptr;
    newptr->next = ptr;
}

void print_ht(){
    struct node *ptr = NULL;
    for(int i=0;i<M;i++){
        ptr = ht.head[i];
        printf("\n%d=",i);
        while(ptr){
            printf(" %d:%d ",ptr->key,ptr->value);    
            ptr = ptr->next;
        }
    }
}

int search_ht(int key){
    int hash = calc_hash(key);
    struct node *ptr = ht.head[hash];
    while (ptr)
    {
        if(ptr->key==key)
            return ptr->value;
        ptr = ptr->next;
    }
    return -1;
    
}

int main(){
    init();
    add_node(5,15);
    add_node(2,1);
    add_node(9,5);
    add_node(15,18);
    add_node(3,1);
    add_node(22,15);
    add_node(7,8);

    print_ht();
    printf("\n%d",search_ht(3));
    return 0;
}