#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#define N 10

class Node{
    public:
    int data;
    Node* next;
};

class Graph{
    public:
    Node* arr[N];
    Graph(){
        for(int i=0;i<N;i++){
            arr[i] = new Node();
            arr[i]->next = NULL;
            arr[i]->data = i;
            }
    }
    void addEdge(int u,int v){
        Node* uptr = new Node();
        uptr->data = v;

        if(!arr[u]->next)
            arr[u]->next = uptr;
        else{
            Node* ptr = arr[u]->next;
            while(ptr->next){
                ptr = ptr->next;
            }
            ptr->next = uptr;
        }
        if(u==v) return;
        Node* vptr = new Node();
        vptr->data = u;
        
        if(!arr[v]->next)
            arr[v]->next = vptr;
        else{
            Node* ptr = arr[v]->next;
            while(ptr->next){
                ptr = ptr->next;
            }
            ptr->next = vptr;
        }
    }

    void bfs(int start){
        bool visited[N];
        for(auto i:visited)
            i=false;
        queue<Node*> q;
        visited[start] = true;
        q.push(arr[start]);
        while(!q.empty()){
            int curr = q.front()->data;
            cout<<curr<<"->";
            q.pop();
            Node* ptr = arr[curr];
            while(ptr){
                if(!visited[ptr->data]){
                    visited[ptr->data] = true;
                    q.push(arr[ptr->data]);
                }
                ptr = ptr->next;
            }
        }
    
    }
    void dfs_helper(bool *visited,int point){
        visited[point] = true;
        cout<<point<<"->";
        Node* ptr = arr[point];
        while(ptr){
            if(!visited[ptr->data])
                dfs_helper(visited,ptr->data);
            ptr = ptr->next;
        } 
    }

    void dfs(int start){
        bool visited[N];
        for(auto i:visited) i=false;
        dfs_helper(visited,start);
    }

    void print(){
        int count = 0;
        for(auto it:arr){
            cout<<"\nFOR vertex "<<count<<"\n";
            Node* ptr = it->next;
            while(ptr){
                cout<<ptr->data<<"->";
                ptr=ptr->next;
            }
            count++;
        }
    }

};

int main(){
    Graph g;
   g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.dfs(0);
    cout<<"\n";
    g.bfs(0);
    return 0;
}