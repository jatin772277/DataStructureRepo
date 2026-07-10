#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int PrimAlgo(const vector<vector<pair<int,int>>> &graph,int n){
    priority_queue< pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;
    vector<bool> visited(n,false);
    pq.push({0,0});
    int sum = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if(visited[node] == true) continue;
        visited[node] = true;
        sum += wt;
        for(auto it : graph[node]){
            int adjNode = it.first;
            int edgeWt = it.second;
            if(!visited[adjNode]){
                pq.push({edgeWt,adjNode});
            }
        }
    }
    return sum;
}
int main(){
    int n = 5;//number of nodes
    vector<vector<pair<int,int>>> graph(n);
    graph[0] = {{1,2},{2,1}};
    graph[1] = {{0,2},{2,1}};
    graph[2] = {{0,1},{1,1},{4,2},{3,2}};
    graph[3] = {{2,2},{4,1}};
    graph[4] = {{2,2},{3,1}};
    int cost = PrimAlgo(graph,n);
    cout<<"Cost Of Minimum Spanning Tree: "<<cost<<endl;
    return 0;
}