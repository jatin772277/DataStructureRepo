#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> BFS(vector<vector<int>>& graph,int source,int V){
    vector<bool> visited(V + 1,false);
    visited[source] = true; 
    queue<int> q;
    q.push(source);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();q.pop();
        bfs.push_back(node);
        for(auto it : graph[node]){
            if(!visited[it]){
                visited[it] = true;
                q.push(it);
            }
        }
    }
    return bfs;
}
int main(){
    int V = 8;
    vector<vector<int>> graph(V + 1);
    graph[0] = {};
    graph[1] = {2,6};
    graph[2] = {3,4,1};
    graph[3] = {1};
    graph[4] = {2,4};
    graph[5] = {4,7};
    graph[6] = {1,7,8};
    graph[7] = {5,6};
    graph[8] = {6};
    vector<int> BFSTraversal = BFS(graph,1,V);
    cout<<"BFS Traversal: ";
    for(int x : BFSTraversal) cout<<x<<" ";
    cout<<endl;
    return 0;
}