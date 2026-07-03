#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>>& graph){
    int n = graph.size();

    vector<vector<int>> reverseGraph(n);
    vector<int> indegree(n, 0);

    for(int i = 0; i < n; i++){
        for(auto it : graph[i]){
            reverseGraph[it].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;

    for(int i = 0; i < n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    vector<int> safeNodes;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        safeNodes.push_back(node);

        for(auto it : reverseGraph[node]){
            indegree[it]--;

            if(indegree[it] == 0)
                q.push(it);
        }
    }

    sort(safeNodes.begin(), safeNodes.end());

    return safeNodes;
}

int main(){
    vector<vector<int>> graph(12);
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
    vector<int> ans = eventualSafeNodes(graph);
    cout << "Eventual Safe Nodes: ";
    for(int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}