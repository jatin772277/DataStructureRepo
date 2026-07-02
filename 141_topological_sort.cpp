#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfs(int source,vector<bool>& visited,stack<int> &st,vector<vector<int>> &graph){
    visited[source] = true;
    for(auto it : graph[source]){
        if(!visited[it]) dfs(it,visited,st,graph);
    }
    st.push(source);
}
vector<int> TopologicalSorting(vector<vector<int>>& graph){
    vector<bool> visited(graph.size(),false);
    stack<int> st;
    for(int i = 0;i < visited.size();i++){
        if(!visited[i]){
            dfs(i,visited,st,graph);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    int V = 6;
    vector<vector<int>> graph(V);
    graph[0] = {};
    graph[1] = {};
    graph[2] = {3};
    graph[3] = {1};
    graph[4] = {0,1};
    graph[5] = {0,2};
    vector<int> topoSort = TopologicalSorting(graph);
    cout<<"Topological Ordering: ";
    for(int i = 0;i < topoSort.size();i++) cout<<topoSort[i]<<" ";
    cout<<endl;
    return 0;
}