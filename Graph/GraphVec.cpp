#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define N 5

class Graph{
    public:
    vector<vector<int>> arr;

    void addEdge(int u,int v){
        arr[u].push_back(v);
        arr[v].push_back(u);
    }


    void print(){
        for(int i =0;i<N;i++){
            cout << "\n Adjacency list of vertex "<< i << "\n head ";
            for (auto x : arr[i])
                cout << "-> " << x;
            printf("\n");
        }
    }

};

int main(){
    Graph g;
    g.addEdge(1,2);
    g.addEdge(0,1);
    g.print();
    return 0;
}