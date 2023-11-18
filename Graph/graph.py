N = 10
visited = [0]*N 


def add_edge(graph,v1,v2):
    graph[v1][v2] = 1
    graph[v2][v1] = 1

def adjacent_matrix(graph):
    print("Adjacent Matrix:")
    for row in graph:
        print(row)

def adjacent_nodes(graph,i):
    nodes = []
    for j in range(N):
        if graph[i][j]==1:
            nodes.append(j)
    return nodes
                

def bft(graph,node):
    bfs(graph,node)
    for i in range(N):
        if visited[i]==0:
            bfs(graph,i)

def bfs(graph,node):
    queue = []
    visited[node] = 1
    queue.append(node)
    while queue:
        node = queue.pop(0)
        print(node,"->",end=" ")
        for i in adjacent_nodes(graph,node):
            if visited[i]==0:
                queue.append(i)
                visited[i]=1
    print("None")


def dft(graph,node):
    dfs(graph,node)
    print("None")
    for i in range(N):
        if visited[i]==0:
            dfs(graph,i)
            print("None")

def dfs(graph,node):
    visited[node] = 1
    print(node,"->",end=" ")
    for i in adjacent_nodes(graph,node):
        if visited[i]==0:
            dfs(graph,i)

def main():
    graph = [[0]*N for i in range(N)]

    add_edge(graph,1,3)
    add_edge(graph,2,3)
    add_edge(graph,4,3)
    add_edge(graph,0,2)
    add_edge(graph,7,2)
    add_edge(graph,1,9)
    add_edge(graph,2,6)
    add_edge(graph,6,0)
    add_edge(graph,5,8)
    add_edge(graph,6,3)    
    adjacent_matrix(graph)
    dft(graph,2)

if __name__ =='__main__':
    main()