#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isCyclic(vector<vector<int>>& graph){
    int n = graph.size();
    vector<int> indegree(n);
    for(int i = 0;i < n;i++){
        for(auto it : graph[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i = 0;i < n;i++){
        if(indegree[i] == 0) q.push(i);
    }
    int count = 0;
    while(!q.empty()){
        int node = q.front();q.pop();count++;
        for(auto it : graph[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    if(count < n) return true;
    else return false;
}
int main(){
    vector<vector<int>> graph1(5);
    graph1[0] = {1};
    graph1[1] = {2};
    graph1[2] = {3,4};
    graph1[3] = {1};
    graph1[4] = {};
    vector<vector<int>> graph2(6);
    graph2[0] = {};
    graph2[1] = {};
    graph2[2] = {3};
    graph2[3] = {1};
    graph2[4] = {0,1};
    graph2[5] = {0,2};
    bool ans1 = isCyclic(graph1);
    bool ans2 = isCyclic(graph2);
    if(ans1) cout<<"Graph1 has Cycle!!!"<<endl;
    else cout<<"Graph1 doesn't Have Any Cycle!!!"<<endl;
    if(ans2) cout<<"Graph2 has Cycle!!!"<<endl;
    else cout<<"Graph2 doesn't Have Any Cycle!!!"<<endl;
    return 0;
}