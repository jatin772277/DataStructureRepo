#include<iostream>
#include<vector>
using namespace std;
bool dfsCheck(int source,const vector<vector<int>>& graph,vector<bool>& visited,
vector<bool>& PathVisited){
    visited[source] = true;
    PathVisited[source] = true;
    for(auto it : graph[source]){
        if(!visited[it]){
            if(dfsCheck(it,graph,visited,PathVisited)) return true;
        }
        else if(PathVisited[it]) return true;
    }
    PathVisited[source] = false;
    return false;
}
bool isCycleDirected(vector<vector<int>>& graph,int V){
    vector<bool> visited(V,false);
    vector<bool> PathVisited(V,false);
    for(int i = 0;i < V;i++){
        if(!visited[i]) if(dfsCheck(i,graph,visited,PathVisited)) return true;
    }
    return false;
}
int main(){
    int V = 10;
    vector<vector<int>> graph(V);
    graph[0] = {1};
    graph[1] = {2};
    graph[2] = {3,6};
    graph[3] = {4};
    graph[4] = {5};
    graph[5] = {};
    graph[6] = {4};
    graph[7] = {1,8,9};
    graph[8] = {9};
    graph[9] = {};
    bool ans = isCycleDirected(graph,V);
    if(ans) cout<<"There is a cycle in graph!!!"<<endl;
    else cout<<"There is No any Cycle!!!"<<endl;
    return 0;
}