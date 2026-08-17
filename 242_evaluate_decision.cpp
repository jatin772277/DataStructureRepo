#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
    double dfs(int node,int target,double prod,
    vector<vector<pair<int,double>>>& graph,vector<bool>& visited){
        if(node == target) return prod;
        visited[node] = true;
        for(auto it : graph[node]){
            int nextNode = it.first;
            double value = it.second;
            if(visited[nextNode]) continue;
            double ans = dfs(nextNode,target,prod * value,graph,visited);
            if(ans != -1.0) return ans;
        }
        return -1.0;
    }
    vector<double> EvaluateDecision(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> mpp;
        int ind = 0;
        for(int i = 0;i < equations.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];
            if(mpp.find(u) == mpp.end()){
                mpp[u] = ind++;
            }
            if(mpp.find(v) == mpp.end()){
                mpp[v] = ind++;
            }
        }
        int totalNode = mpp.size();
        vector<vector<pair<int,double>>> graph(totalNode);
        for(int i = 0;i < equations.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];
            graph[mpp[u]].push_back({mpp[v],values[i]});
            graph[mpp[v]].push_back({mpp[u],1 / values[i]});
        }
        vector<double> ans;
        for(int i = 0;i < queries.size();i++){
            string u = queries[i][0];
            string v = queries[i][1];
            if(mpp.find(u) == mpp.end() || mpp.find(v) == mpp.end()){
                ans.push_back(-1.0);
                continue;
            }
            if(u == v){
                ans.push_back(1.0);
                continue;
            }
            vector<bool> visited(totalNode,false);
            double result = dfs(mpp[u],mpp[v],1.0,graph,visited);
            ans.push_back(result);
        }
        return ans;
    }
int main(){
    cout<<"Refer to leetcode 399!!"<<endl;
    vector<vector<string>> equations = {
        {"a","b"},
        {"b","c"}
    };
    vector<double> values = {2.0,3.0};
    vector<vector<string>> queries = {
        {"a","c"},
        {"b","a"},
        {"a","e"},
        {"a","a"},
        {"x","x"}
    };
    vector<double> ans = EvaluateDecision(equations,values,queries);
    cout<<"answer: ";
    for(auto x : ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}