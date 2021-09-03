#include<iostream>

using namespace std;

#define MAX 10

class Tree{
    char tree[MAX];
    public:
        void root(char data){
            if(tree[0]!='\0')
                cout<<"\nroot exists\n";
            else tree[0] =data;
        }
        int left(int index){
            return 2*index+1;
        }
        int right(int index){
            return 2*index+2;
        }

        void set_left(char dat,int parent){
            if(tree[parent]=='\0' )
                cout<<"parent not found";
            else
                tree[left(parent)]=dat;
        }
        
        void set_right(char dat,int parent){
            if(tree[parent]=='\0')
                cout<<"parent not found";
            else
                tree[right(parent)]=dat;
        }

        int parent(int index){
            return (index-1)/2;
        }

        void print_arr(){
            for(int i =0;i<MAX;i++)
                if(tree[i]!='\0')
                    cout<<tree[i];
                else cout<<"-";
        }

        void inorder(int index){
            if(tree[index]=='\0' || !isalpha(tree[index]))
                return;
            inorder(left(index));
            cout<<tree[index];
            inorder(right(index));
        }

        
        void preorder(int index){
            if(tree[index]=='\0' || !isalpha(tree[index]))
                return;
            cout<<tree[index];
            preorder(left(index));
            preorder(right(index));
        }
        
        void postorder(int index){
            if(tree[index]=='\0' || !isalpha(tree[index]))
                return;
            postorder(left(index));
            postorder(right(index));
            cout<<tree[index];
        }
};

int main(){
    Tree t;
    t.root('A');
    t.set_left('B',0);
    t.set_right('C',0);
    t.set_left('E',2);
    t.set_right('F',2);
    t.set_right('D',1);
    t.set_left('H',6);
    t.set_right('I',6);
    t.set_left('G',5);
    t.inorder(0);
    cout<<"\n";
    t.preorder(0);
    cout<<"\n";
    t.postorder(0);
    return 0;

}