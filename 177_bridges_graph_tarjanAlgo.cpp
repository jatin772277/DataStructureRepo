#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int timer = 1;
    void dfs(int node,int parent,vector<bool> &visited,vector<vector<int>>& graph,
    vector<int> &tin,vector<int> &low,vector<vector<int>>& bridges){
        visited[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it : graph[node]){
            if(it == parent) continue;
            if(!visited[it]){
                dfs(it,node,visited,graph,tin,low,bridges);
                low[node] = min(low[node],low[it]);
                if(low[it] > tin[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node] = min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(auto it : connections){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n,false);
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> bridges;
        dfs(1,-1,visited,graph,tin,low,bridges);
        return bridges;
    }
};
int main(){
    vector<vector<int>> connections;
    int n = 13;
    connections.push_back({1,2});
    connections.push_back({1,4});
    connections.push_back({2,3});
    connections.push_back({3,4});
    connections.push_back({4,5});
    connections.push_back({5,6});
    connections.push_back({6,7});
    connections.push_back({6,9});
    connections.push_back({7,8});
    connections.push_back({9,8});
    connections.push_back({8,10});
    connections.push_back({10,11});
    connections.push_back({10,12});
    connections.push_back({11,12});
    Solution ds;
    vector<vector<int>> bridge = ds.criticalConnections(n,connections);
    cout<<"Bridge Edges: "<<endl;
    for(auto it : bridge){
        cout<<"( "<<it[0]<<" ,"<<it[1]<<" )"<<" ";
    }
    cout<<endl;
    return 0;
}
