#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    char color;
    Node* left;
    Node* right;
};

class Tree{
    public:
        Node *root;

        Tree(){
            root = NULL;
        }

        Node* insert(int data){
            Node* newptr = new Node();
            newptr->data = data;
            if(!root){
                root = newptr;
                newptr->color = 'b';
                return newptr;
            }

            Node* ptr = root;
            for(;;){
                if(data<ptr->data)
                    if(!ptr->left){
                        ptr->left = newptr;
                        break;
                        }
                    else
                        ptr = ptr->left;
                else {
                    if(!ptr->right){
                        ptr->right = newptr;
                        break;
                        }
                    else ptr = ptr->right;
                }
            }
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

        Node* remove(int data,Node* ptr){
            if(!ptr) return ptr;
            if(data<ptr->data)
                ptr->left = remove(data,ptr->left);
            else if(data>=ptr->data)
                ptr->right = remove(data,ptr->right);
            else{
            //0 child
                if(!ptr->right && !ptr->left){
                    delete ptr;
                    ptr = NULL;
                    return NULL;
                }   
                //1 child
                else if(!ptr->right){
                    Node*temp = ptr->left;
                    delete ptr;
                    return temp;
                }
                else if(!ptr->left){
                    Node*temp = ptr->right;
                    delete ptr;
                    return temp;
                }
                //2 child
        
                Node* pred = predecessor(ptr->left);
                ptr->data = pred->data;
                delete pred;
                ptr->left = remove(pred->data,ptr->left);
            }
            return ptr;
        }

        Node* predecessor(Node *node){
            Node *ptr = node;

            while(ptr && ptr->right)
                ptr = ptr->right;

            return ptr;
        }

};


int main(){

    int arr[11] = {11,6,8,19,4,10,5,17,43,49,31};
    Tree t;
    for(int i = 0;i<11;i++)
        t.insert(arr[i]);
    
    t.inorder(t.root);
    cout<<"\n";
    t.root = t.remove(43,t.root);
    t.inorder(t.root);
    cout<<"\n";
    return 0;
}