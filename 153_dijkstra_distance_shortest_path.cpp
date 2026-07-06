#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
vector<int> DijkstraAlgo(const vector<vector<pair<int,int>>>& graph,int source){
    vector<int> dist(graph.size(),INT_MAX);
    dist[source] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,source});
    while(!pq.empty()){
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        for(auto it : graph[node]){
            int edgeWt = it.second;
            int v = it.first;
            if(distance + edgeWt < dist[v]){
                dist[v] = distance + edgeWt;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
int main(){
    int V = 6;
    vector<vector<pair<int,int>>> graph(V);
    graph[0] = {{1,4},{2,4}};
    graph[1] = {{0,4},{2,2}};
    graph[2] = {{0,4},{1,2},{3,3},{4,1},{5,6}};
    graph[3] = {{2,3},{5,2}};
    graph[4] = {{2,1},{5,3}};
    graph[5] = {{3,2},{4,3},{2,6}};
    int src = 2;
    vector<int> dist = DijkstraAlgo(graph,src);
    cout<<"Shortest Distance From "<<src<<": ";
    for(int i = 0;i < dist.size();i++) cout<<"("<<i<<"->"<<dist[i]<<")"<<" ";
    cout<<endl;
    return 0;
}