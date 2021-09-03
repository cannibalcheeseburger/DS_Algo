#include<iostream>
using namespace std;

#define N 3

class Graph{
    public:
    int graph[N][N];
    Graph(){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                graph[i][j]=0;
    }
    void addEdge(int u,int v){
        graph[u][v]=graph[v][u]=1;
    }

    void print(){
        for(int i=0;i<N;i++){
            cout<<"\nFor vertex "<<i<<"\n";
            for(int j=0;j<N;j++)
                if(graph[i][j])
                    cout<<j<<"->";
        }
    }

};


int main(){
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,2);
    g.print();
    return 0;
}