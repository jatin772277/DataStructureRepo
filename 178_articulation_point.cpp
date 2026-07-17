#include<iostream>
#include<vector>
using namespace std;
int timer = 0;
void dfs(int node,int parent,vector<bool> &visited,vector<int> &tin,vector<int>& low,
        vector<bool> &mark,const vector<vector<int>>& graph){
            visited[node] = true;
            tin[node] = low[node] = timer;
            timer++;
            int child = 0;
            for(auto it : graph[node]){
                if(it == parent) continue;
                if(!visited[it]){
                    dfs(it,node,visited,tin,low,mark,graph);
                    low[node] = min(low[node], low[it]);
                    if(low[it] >= tin[node] && parent != -1){
                        mark[node] = true;
                    }
                    child++;
                }
                else low[node] = min(low[node],tin[it]);
            }
            if(child > 1 && parent == -1) mark[node] = true;
}
vector<int> ArticulationPoint(vector<vector<int>>& graph){
    int n = graph.size();
    vector<bool> visited(n,false);
    vector<int> tin(n);
    vector<int> low(n);
    vector<bool> mark(n,false);
    for(int i = 0;i < n;i++){
        if(!visited[i]){
            dfs(i,-1,visited,tin,low,mark,graph);
        }
    }
    vector<int> ans;
    for(int i = 0;i < n;i++){
        if(mark[i]) ans.push_back(i);
    }
    if(ans.size() == 0) return {-1};
    return ans;
}
int main(){
    int n = 7;
    vector<vector<int>> graph(n);
    graph[0] = {1,2,3};
    graph[1] = {0};
    graph[2] = {0,3,4,5};
    graph[3] = {0,2};
    graph[4] = {2,6};
    graph[5] = {2,6};
    graph[6] = {4,5};
    vector<int> articulatePoints = ArticulationPoint(graph);
    cout<<"Graph have Articulation point: ";
    for(int x : articulatePoints) cout<<x<<" ";
    cout<<endl;
    return 0;
}