#include<iostream>
#include<vector>
using namespace std;
void dfs(int source,vector<vector<int>>& graph,vector<bool> &visited,vector<int>& list){
    visited[source] = true;
    list.push_back(source);
    for(auto it : graph[source]){
        if(!visited[it]){
            dfs(it,graph,visited,list);
        }
    }
}
vector<int> DFS(vector<vector<int>>& graph,int source,int V){
    vector<bool> visited(V+1,false);
    vector<int> list;
    dfs(source,graph,visited,list);
    return list;
}
int main(){
    int V = 8;
    vector<vector<int>> graph(V + 1);
    graph[0] = {};
    graph[1] = {2,3};
    graph[2] = {1,5,6};
    graph[3] = {1,4,7};
    graph[4] = {3,8};
    graph[5] = {2};
    graph[6] = {2};
    graph[7] = {3,8};
    graph[8] = {4,7};
    cout<<"DFS Traversal: ";
    vector<int> DFSTraversal = DFS(graph,1,V);
    for(int x : DFSTraversal) cout<<x<<" ";
    cout<<endl;
    return 0;
}