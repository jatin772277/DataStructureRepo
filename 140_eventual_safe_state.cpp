// There is a directed graph of n nodes with each node labeled from 0 to n - 1. 
// The graph is represented by a 0-indexed 2D integer array graph where graph[i] 
// is an integer array of nodes adjacent to node i, meaning there is an edge 
// from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges.
// A node is a safe node if every possible path starting from 
// that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. 
// The answer should be sorted in ascending order
#include<iostream>
#include<vector>
using namespace std;
bool dfsCheck(int source,vector<vector<int>>& graph,vector<bool>& visited,
    vector<bool>& pathVisited,vector<bool>& check){
        visited[source] = true;
        pathVisited[source] = true;
        for(auto it : graph[source]){
            if(!visited[it]){
                if(dfsCheck(it,graph,visited,pathVisited,check)){
                    check[source] = 0;
                    return true;
                }
            }
            else if(pathVisited[it]){
                    check[source] = 0;
                    return true;
            }
        }
        check[source] = 1;
        pathVisited[source] = false;
        return false;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(),false);
        vector<bool> pathVisited(graph.size(),false);
        vector<bool> check(graph.size(),false);
        vector<int> result;
        for(int i = 0;i < graph.size();i++){
            if(!visited[i]){
                dfsCheck(i,graph,visited,pathVisited,check);
            }
        }
        for(int i = 0;i < graph.size();i++){
            if(check[i]) result.push_back(i);
        }
        return result;
}
int main(){
    int V = 12;
    vector<vector<int>> graph(V);
    graph[0] = {1};
    graph[1] = {2};
    graph[2] = {3};
    graph[3] = {4,5};
    graph[4] = {6};
    graph[5] = {6};
    graph[6] = {7};
    graph[7] = {};
    graph[8] = {1,9};
    graph[9] = {10};
    graph[10] = {8};
    graph[11] = {9};
    vector<int> safeNodes = eventualSafeNodes(graph);
    cout<<"Safe Nodes: ";
    for(int x : safeNodes) cout<<x<<" ";
    cout<<endl;
    return 0;
}