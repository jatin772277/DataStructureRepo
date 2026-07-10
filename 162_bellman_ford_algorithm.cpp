#include<iostream>
#include<vector>
using namespace std;
vector<int> Bellman_fordAlgo(int n,const vector<pair<int,pair<int,int>>>& edges,int source){
    vector<int> dist(n,1e8);
    dist[source] = 0;
    for(int i = 0;i < n-1;i++){
        for(auto it : edges){
            int u = it.first;
            int v = it.second.first;
            int wt = it.second.second;
            if(dist[u] + wt < dist[v] && dist[u] != 1e8){
                dist[v] = dist[u] + wt;
            }
        }
    }
    //Nth Relaxation for checking Negative Cycles
    for(auto it : edges){
        int u = it.first;
        int v = it.second.first;
        int wt = it.second.second;
        if(dist[u] + wt < dist[v] && dist[u] != 1e8){
            return {-1};
        }
    }
    return dist;
}
int main(){
    vector<pair<int,pair<int,int>>> edges;
    edges.push_back({3,{2,6}});
    edges.push_back({5,{3,1}});
    edges.push_back({0,{1,5}});
    edges.push_back({1,{5,-3}});
    edges.push_back({1,{2,-2}});
    edges.push_back({3,{4,-2}});
    edges.push_back({2,{4,3}});
    int n = 6;//Number of Nodes
    int source = 0;
    vector<int> ans = Bellman_fordAlgo(n,edges,source);
    cout<<"If Array has only -1 then graph have a negative cycle!!!"<<endl;
    cout<<"Distance From Source "<<source<<" To every Other Node: ";
    for(int x : ans) cout<<x<<" ";
    cout<<endl;
    vector<pair<int,pair<int,int>>> edges1;
    edges1.push_back({0,{1,-1}});
    edges1.push_back({1,{2,-2}});
    edges1.push_back({2,{0,2}});
    int n1 = 3;
    vector<int> ans1 = Bellman_fordAlgo(n1,edges1,source);
    cout<<"If Array has only -1 then graph have a negative cycle!!!"<<endl;
    cout<<"Distance From Source "<<source<<" To every Other Node: ";
    for(int x : ans1) cout<<x<<" ";
    cout<<endl;
    return 0;
}