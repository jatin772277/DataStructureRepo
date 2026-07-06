#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
vector<int> DijkstraAlgoPathPrint(const vector<vector<int>>& edges,int n,int source,int end){
    vector<vector<pair<int,int>>> graph(n + 1);
    for(auto it : edges){
        graph[it[0]].push_back({it[1], it[2]});
        graph[it[1]].push_back({it[0], it[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++) parent[i] = i;
    dist[source] = 0;
    pq.push({0, source});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int dis = it.first;
        int node = it.second;
        if(dis > dist[node]) continue;
        for(auto adj : graph[node]){
            int adjNode = adj.first;
            int edgeWt = adj.second;
            if(dis + edgeWt < dist[adjNode]){
                dist[adjNode] = dis + edgeWt;
                parent[adjNode] = node;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    if(dist[end] == INT_MAX) return {-1};
    vector<int> path;
    int node = end;
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    return path;
}

int main(){
    vector<vector<int>> edges;
    int n = 5;
    edges.push_back({1,2,2});
    edges.push_back({1,4,1});
    edges.push_back({2,5,5});
    edges.push_back({2,3,4});
    edges.push_back({4,3,3});
    edges.push_back({3,5,1});
    int source = 1;
    int end = 5;
    vector<int> path = DijkstraAlgoPathPrint(edges,n,source,end);
    cout<<"If path Exists then path will be printed else -1"<<endl;
    for(int i=0;i<path.size();i++){
        if(i==path.size()-1) cout<<path[i]<<endl;
        else cout<<path[i]<<" -> ";
    }
    return 0;
}