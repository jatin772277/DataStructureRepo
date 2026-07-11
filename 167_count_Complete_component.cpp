//Complete Component means component is complete graph all vertices connected to all
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void dfs(vector<vector<int>> &graph,vector<bool>& visited,int source){
        visited[source] = true;
        for(auto it : graph[source]){
            if(!visited[it]){
                dfs(graph,visited,it);
            }
        }
}

vector<int> DiffComponentNodes(vector<vector<int>> &graph){
        vector<bool> visited(graph.size(),false);
        vector<int> nodes;
        int n = graph.size();
        for(int i = 0;i < n;i++){
            if(!visited[i]){
                nodes.push_back(i);
                dfs(graph,visited,i);
            }
        }
        return nodes;
}

bool isComplete(vector<vector<int>>& graph,vector<bool>& visited,int source){
    queue<int> q;
        q.push(source);
        visited[source] = true;
        vector<int> component;
        while(!q.empty()){
            int node = q.front();q.pop();
            component.push_back(node);
            for(auto it : graph[node]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        int k = component.size();
        for(auto node : component){
            if(graph[node].size() != (k-1)) return false;
        }
        return true;
}

int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    for(int i = 0;i < edges.size();i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> nodes = DiffComponentNodes(graph);
    int count = 0;
    vector<bool> visited(n,false);
    for(int i = 0;i < nodes.size();i++){
        if(isComplete(graph,visited,nodes[i])) count++;
        else continue;
    }
    return count;
}
int main(){
    vector<vector<int>> edges;
    edges.push_back({0,1});
    edges.push_back({1,2});
    edges.push_back({2,0});
    edges.push_back({3,4});
    int n = 6;//Number of Nodes
    int ans = countCompleteComponents(n,edges);
    cout<<"graph contains "<<ans<<" Complete Component in it.!!!!!!!!!!!"<<endl;
    return 0;
}