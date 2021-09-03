#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

class Tree{
    public:
        Node *root;

        Tree(){
            root = NULL;
        }

        Node* create(){
            //cout<<"Enter data: ";
            int data;
            cin>>data;
            if(data==-1)
                return NULL;
            Node* newptr= new Node();
            if(!root){
                root = newptr;
            }
            newptr->data = data;
            //cout<<"Left Child";
            newptr->left = create();
            //cout<<"Right Child";
            newptr->right = create();
            return newptr;
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
};


int main(){
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif

    Tree t;
    t.create();
    t.inorder(t.root);
    cout<<"\n";
    t.preorder(t.root);
    cout<<"\n";
    t.postorder(t.root);

    return 0;
}