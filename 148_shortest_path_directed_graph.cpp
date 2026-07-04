#include<iostream>
#include<climits>
#include<vector>
#include<stack>
using namespace std;
void dfs(int source,vector<bool> &visited,stack<int>& st,vector<vector<pair<int,int>>>& graph){
    visited[source] = true;
    for(auto it : graph[source]){
        if(!visited[it.first]){
            dfs(it.first,visited,st,graph);
        }
    }
    st.push(source);
    return;
}
vector<int> shortestDistance(int n,const vector<vector<int>>& edges){
    vector<vector<pair<int,int>>> graph(n);
    for(int i = 0;i < edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        graph[u].push_back({v,wt});
    }
    stack<int> st;
    vector<bool> visited(n,false);
    for(int i = 0;i < n;i++){
        if(!visited[i]){
            dfs(i,visited,st,graph);
        }
    }
    vector<int> dist(n,INT_MAX);
    dist[0] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it : graph[node]){
            int v = it.first;
            int wt = it.second;
            if(dist[v] > dist[node] + wt){
                dist[v] = wt + dist[node];
            }
        }
    }
    return dist;
}
int main(){
    vector<vector<int>> edges;
    int n = 6;//Number of Nodes
    edges.push_back({0,1,2});
    edges.push_back({0,4,1});
    edges.push_back({1,2,3});
    edges.push_back({4,2,2});
    edges.push_back({4,5,4});
    edges.push_back({2,3,6});
    edges.push_back({5,3,1});
    vector<int> dist = shortestDistance(n,edges);
    cout<<"Shortest Distance from Source 0: ";
    for(int x : dist) cout<<x<<" ";
    cout<<endl;
    return 0;
}