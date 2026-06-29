#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool detect(vector<bool> &visited,int src,const vector<vector<int>> &graph){
    visited[src] = true;
    queue<pair<int,int>> q;
    q.push({src, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto x : graph[node]){
            if(!visited[x]){
                visited[x] = true;
                q.push({x,node});
            }
            else if(parent != x) return true;
        }
    }
    return false;
}
bool isCycleInGraph(const vector<vector<int>>& graph,int V){
    vector<bool> visited(V + 1,false);
    visited[0] = true;
    for(int i = 1;i <= V;i++){
        if(!visited[i]){
            if(detect(visited,i,graph)) return true;
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
    bool isCycle = isCycleInGraph(graph,V);
    if(isCycle) cout<<"Cycle Existed in the graph!!!"<<endl;
    else cout<<"There is no Cycle in graph!!"<<endl;
    return 0;
}