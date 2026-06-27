#include<iostream>
#include<vector>
using namespace std;
void dfs(const vector<vector<int>>& graph,vector<bool>& visited,int source){
    visited[source] = true;
    for(auto it : graph[source]){
        if(!visited[it]){
            dfs(graph,visited,it);
        }
    }
}
int ProvincesNum(const vector<vector<int>> &graph,int V){
    vector<bool> visited(V + 1,false);
    int count = 0;
    for(int i = 1;i <= V;i++){
        if(!visited[i]){
            count++;
            dfs(graph,visited,i);
        }
    }
    return count;
}
int main(){
    int V = 8;
    vector<vector<int>> graph(V + 1);
    graph[0] = {};
    graph[1] = {2};
    graph[2] = {1,3};
    graph[3] = {2};
    graph[4] = {5};
    graph[5] = {4,6};
    graph[6] = {5};
    graph[7] = {8};
    graph[8] = {7};
    int NumberProvinces = ProvincesNum(graph,V);
    cout<<"Number of Provinces (Connected Components): "<<NumberProvinces<<endl;
    return 0;
}