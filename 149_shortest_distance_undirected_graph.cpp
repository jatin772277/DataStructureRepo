#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
vector<int> ShortestDistanceWithSource(vector<pair<int,int>>& edges,int n,int source){
    vector<vector<int>> graph(n);
    for(int i = 0;i < edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        graph[u].push_back(v);
    }
    queue<pair<int,int>> q;
    int wt = 1;
    vector<int> dist(n,INT_MAX);
    dist[source] = 0;
    q.push({source,0});
    while(!q.empty()){
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();
        for(auto it : graph[node]){
            if(dist[it] > dist[node] + wt){
                dist[it] = dist[node] + wt;
                q.push({it,distance + 1});
            }
        }
    }
    for(int i = 0;i < dist.size();i++) if(dist[i] == INT_MAX) dist[i] = -1;
    return dist;
}
int main(){
    int n = 10;//number of nodes
    vector<pair<int,int>> edges;
    edges.push_back({0,1});
    edges.push_back({0,3});
    edges.push_back({1,3});
    edges.push_back({1,2});
    edges.push_back({3,4});
    edges.push_back({4,5});
    edges.push_back({5,6});
    edges.push_back({2,6});
    edges.push_back({6,7});
    edges.push_back({7,8});
    edges.push_back({6,8});
    int src = 0;
    vector<int> dist = ShortestDistanceWithSource(edges,n,src);
    cout<<"Shortest Distance of every Node from source "<<src<<": ";
    for(int x : dist) cout<<x<<" ";
    cout<<endl;
    return 0;
}