// we'll take out edge and place to make the graph components connected
#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
    vector<int> rank,parent;
    int extraEdge;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        extraEdge = 0;
        for(int i = 0;i <= n;i++) parent[i] = i;
    }
    int findUpar(int u){
        if(u == parent[u]) return u;
        return parent[u] = findUpar(parent[u]);
    }
    void UnionByRank(int u,int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v){
            extraEdge++;
            return;
        }
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    int UniqueParent(){
        int count = 0;
        for(int i = 0;i < parent.size();i++){
            if(i == findUpar(i)) count++;
        }
        return count;
    }
    int ReturnExtraEdge(){
        return extraEdge;
    }
};
int ObtainConnectedGraph(int n,vector<vector<int>>& edges){
    DisjointSet ds(n);
    for(int i = 0;i < edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        ds.UnionByRank(u,v);
    }
    int ComponentN = ds.UniqueParent();
    int extraEdges = ds.ReturnExtraEdge();
    if(extraEdges >= (ComponentN - 1)) return (ComponentN-1);
    else return -1;
}
int main(){
    vector<vector<int>> edges;
    int n = 8;
    edges.push_back({0,1});
    edges.push_back({0,2});
    edges.push_back({0,3});
    edges.push_back({1,2});
    edges.push_back({2,3});
    edges.push_back({4,5});
    edges.push_back({5,6});
    edges.push_back({7,8});
    int MinOper = ObtainConnectedGraph(n,edges);
    cout<<"Operation : Remove An extra Edge from Any component to add 2 component!!!"<<endl
    <<"If It's Possible return Minimum Operations!!"<<endl<<" else return -1"<<endl;
    cout<<"Minimum Operations: "<<MinOper<<endl;
    return 0;
}