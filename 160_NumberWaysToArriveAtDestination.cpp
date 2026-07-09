#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int NumberWaysShortestGraph(const vector<vector<pair<int,int>>>& graph,int source,int end){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int n = graph.size();
    vector<int> ways(n,0);
    ways[source] = 1;
    vector<long long> dist(n,LLONG_MAX);
    dist[source] = 0;
    pq.push({0,source});
    const int mod = (1e9 + 7);
    while(!pq.empty()){
        int node = pq.top().second;
        int distance = pq.top().first;pq.pop();
        if(distance > dist[node]) continue;
        for(auto it : graph[node]){
            int neigh = it.first;
            int edgeWt = it.second;
            if(edgeWt + distance < dist[neigh]){
                dist[neigh] = edgeWt + distance;
                pq.push({edgeWt + distance , neigh});
                ways[neigh] = ways[node];
            }
            else if(edgeWt + distance == dist[neigh]) ways[neigh] = (ways[neigh] + ways[node]) % mod;
        }
    }
    return ways[end] % mod;
}
int main(){
    int n = 9;//number of Nodes;
    vector<vector<pair<int,int>>> graph(n);
    graph[0] = {{1,1},{2,2},{3,1},{4,2}};
    graph[1] = {{0,1},{5,2}};
    graph[2] = {{0,2},{5,1}};
    graph[3] = {{0,1},{5,2},{7,3},{6,2}};
    graph[4] = {{0,2},{6,1}};
    graph[5] = {{1,2},{2,1},{3,2},{8,1}};
    graph[6] = {{3,2},{4,1},{8,1}};
    graph[7] = {{3,3},{8,1}};
    graph[8] = {{5,1},{6,1},{7,1}};
    int source = 0;
    int dest = 8;
    int NumWaysShortest = NumberWaysShortestGraph(graph,source,dest);
    cout<<"Number of Ways to Reach To Destination "<<dest<<
    " From Source "<<source<<" is: "<<NumWaysShortest<<endl;
    return 0;
}