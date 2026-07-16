#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfs(int source,vector<bool> &visited,stack<int>& st,vector<vector<int>>& graph){
    visited[source] = true;
    for(auto it : graph[source]){
        if(!visited[it]){
            dfs(it,visited,st,graph);
        }
    }
    st.push(source);
}
void dfs1(int source,vector<bool> &visited,vector<vector<int>>& adjT){
    visited[source] = true;
    for(auto it : adjT[source]){
        if(!visited[it]){
            dfs1(it,visited,adjT);
        }
    }
}
int kosarajuAlgo(vector<vector<int>>& graph){
    int n = graph.size();
    vector<bool> visited(n,false);
    stack<int> st;
    for(int i = 0;i < n;i++){
        if(!visited[i]){
            dfs(i,visited,st,graph);
        }
    }
    vector<vector<int>> adjT(n);
    for(int i = 0;i < n;i++){
        visited[i] = false;
        for(auto it : graph[i]){
            adjT[it].push_back(i);
        }
    }
    int scc = 0;
    while(!st.empty()){
        int node = st.top();st.pop();
        if(!visited[node]){
            scc++;
            dfs1(node,visited,adjT);
        }
    }
    return scc;
}
int main(){
    int n = 8;
    vector<vector<int>> graph(n);
    graph[0] = {1};
    graph[1] = {2};
    graph[2] = {0,3};
    graph[3] = {4};
    graph[4] = {5,7};
    graph[5] = {6};
    graph[6] = {4,7};
    graph[7] = {};
    int scc = kosarajuAlgo(graph);
    cout<<"There is "<<scc<<" Strongly Connected Components!!"<<endl;
    cout<<"SCC means In that component any pair can go to like(u,v) so u to v and"<<endl
    <<" v to u there is some path While Graph is Directed!"<<endl;
    return 0;
}