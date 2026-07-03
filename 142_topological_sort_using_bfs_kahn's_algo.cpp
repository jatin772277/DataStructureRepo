#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> KahnAlgo(vector<vector<int>>& graph){
    vector<int> indegree(graph.size());
    for(int i = 0;i < graph.size();i++){
        for(auto it : graph[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i = 0;i < graph.size();i++){
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();q.pop();
        topo.push_back(node);
        for(auto it : graph[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
}
int main(){
    vector<vector<int>> graph(6);
    graph[0] = {};
    graph[1] = {};
    graph[2] = {3};
    graph[3] = {1};
    graph[4] = {0,1};
    graph[5] = {0,2};
    vector<int> topo = KahnAlgo(graph);
    cout<<"Topological Ordering Using BFS: (Kahn's Algorithm): ";
    for(int x : topo) cout<<x<<" ";
    cout<<endl;
    return 0;
}