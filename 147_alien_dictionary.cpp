#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> topoSort(int k,vector<vector<int>> &graph){
    vector<int> indegree(k);
    for(int i = 0;i < graph.size();i++){
        for(auto it : graph[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i = 0;i < k;i++) if(indegree[i] == 0) q.push(i);
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
string findAlienOrder(vector<string>& dict,int k){
    vector<vector<int>> graph(k);
    int n = dict.size();
    for(int i = 0;i < n - 1;i++){
        string w1 = dict[i];
        string w2 = dict[i+1];
        int len = min(w1.size(),w2.size());
        for(int ptr = 0;ptr < len;ptr++){
            if(w1[ptr] != w2[ptr]){
                graph[w1[ptr] - 'a'].push_back(w2[ptr] - 'a');
                break;
            }
        }
    }
    vector<int> topo = topoSort(k,graph);
    string order = "";
    for(auto it : topo) order += char(it + 'a');
    return order;
}
int main(){
    int N = 5;
    int k = 5;//Number of alphabets;
    vector<string> dict(5);
    dict[0] = "baa";
    dict[1] = "abcd";
    dict[2] = "abca";
    dict[3] = "cab";
    dict[4] = "cad";
    string alienorder = findAlienOrder(dict,k);
    cout<<"Alien Order: "<<alienorder<<endl;
    return 0;
}