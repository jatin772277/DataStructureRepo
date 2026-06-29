#include<iostream>
#include<vector>
using namespace std;
bool dfs(int node,int parent,vector<bool> &visited,const vector<vector<int>> graph){
    visited[node] = true;
    for(auto adj : graph[node]){
        if(!visited[adj]){
            if(dfs(adj,node,visited,graph)) return true;
        }
        else if(adj != parent) return true;
    }
    return false;
}
bool isCycleinGraph(vector<vector<int>> &graph,int V){
    vector<bool> visited(V+1);
    visited[0] = true;
    for(int i = 0;i < V;i++){
        if(!visited[i]){
            if(dfs(i,-1,visited,graph)) return true;
        }
    }
    return false;
}
int main(){
    int V = 7;
    vector<vector<int>> graph(V + 1);
    graph[0] = {};
    graph[1] = {2,3};
    graph[2] = {1,5};
    graph[3] = {1,4,6};
    graph[4] = {3};
    graph[5] = {2,7};
    graph[6] = {3,7};
    graph[7] = {5,6};
    bool isCycle = isCycleinGraph(graph,V);
    if(isCycle) cout<<"There is Cycle in the graph!!"<<endl;
    else cout<<"There is NO any cycle!!!"<<endl;
    return 0;
}