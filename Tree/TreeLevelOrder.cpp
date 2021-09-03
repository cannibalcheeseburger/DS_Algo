#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(){
        left = NULL;
        right = NULL;
    }
};

class Tree{
    public:
        queue<Node*> q;
        Node *root;

        Tree(){
            root = NULL;
        }

        void insert(int data){
            Node* ptr = new Node();
            ptr->data = data;
            if(!root)
                root = ptr;
            else if(!q.front()->left)
                q.front()->left = ptr;
            else {
                q.front()->right = ptr;
                q.pop();
            } 
            q.push(ptr);

        }

        void inorder(Node* temp){
            if (temp == NULL)
                return;
        
            inorder(temp->left);
            cout << temp->data << ' ';
            inorder(temp->right);
        }
        void preorder(Node* temp){
            if (temp == NULL)
                return;
            cout << temp->data << ' ';
            preorder(temp->left);
            preorder(temp->right);
        }
        void postorder(Node* temp){
            if (temp == NULL)
                return;
        
            postorder(temp->left);
            postorder(temp->right);
            cout << temp->data << ' ';
        }

        void print_levels(){
            if(!root)
                return;
            queue<Node*> p;
            p.push(root);

            while(!p.empty()){
                cout<<p.front()->data<<" ";
                if(p.front()->left!=NULL)
                    p.push(p.front()->left);
                if(p.front()->right!=NULL)
                    p.push(p.front()->right);
                p.pop();
            }
        }
};


int main(){

    int arr[] = {11,2,4,1,6,22,15,7,93,2};
    Tree t;
    for(int i =0;i<sizeof(arr)/sizeof(int);i++)
        t.insert(arr[i]);
    t.print_levels();
    cout<<"\n";
    t.inorder(t.root);
    return 0;
}