#include<iostream>
#include<vector>
#include<set>
#include<climits>
using namespace std;
vector<int> DijkstraAlgo(const vector<vector<pair<int,int>>> &graph,int source){
    set<pair<int,int>> st;
    vector<int> dist(graph.size(),INT_MAX);
    st.insert({0,source});
    dist[source] = 0;
    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int distance = it.first;
        st.erase(it);
        for(auto it : graph[node]){
            int v = it.first;
            int edgeWt = it.second;
            if(distance + edgeWt < dist[v]){
                if(dist[v] != INT_MAX) st.erase({dist[v],v});
                dist[v] = distance + edgeWt;
                st.insert({dist[v],v});
            }
        }
    }
    return dist;
}
int main(){
    int V = 6;
    vector<vector<pair<int,int>>> graph(V);
    graph[0] = {{1,4},{2,4}};
    graph[1] = {{0,4},{2,2}};
    graph[2] = {{0,4},{1,2},{3,3},{4,1},{5,6}};
    graph[3] = {{2,3},{5,2}};
    graph[4] = {{2,1},{5,3}};
    graph[5] = {{3,2},{4,3},{2,6}};
    int src = 2;
    vector<int> dist = DijkstraAlgo(graph,src);
    cout<<"Shortest Distance From "<<src<<": ";
    for(int i = 0;i < dist.size();i++) cout<<"("<<i<<"->"<<dist[i]<<")"<<" ";
    cout<<endl;
    return 0;
}