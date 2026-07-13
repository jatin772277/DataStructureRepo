#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
    vector<int> parent,rank;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i = 1;i <= n;i++) parent[i] = i;
    }
    int FindUpar(int u){
        if(u == parent[u]) return u;
        return parent[u] = FindUpar(parent[u]);
    }
    void UnionByRank(int u,int v){
        int ulp_u = FindUpar(u);
        int ulp_v = FindUpar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    int UniqueParent(){
        int count = 0;
        for(int i = 1;i < parent.size();i++){
            if(FindUpar(i) == i) count++;
        }
        return count;
    }
};
int NumOfProvinces(int n,vector<vector<int>> &adjMatrix){
    DisjointSet ds(n);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(adjMatrix[i][j] == 1) ds.UnionByRank(i,j);
        }
    }
    return ds.UniqueParent();
}
int main(){
    int n = 7;
    vector<vector<int>> adjMatrix = {
        {0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0},
        {0,1,0,1,1,0,0,0},
        {0,0,1,0,0,0,0,0},
        {0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,1,0},
        {0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0}
    };
    int num = NumOfProvinces(n,adjMatrix);
    cout<<"Number of Provinces: "<<num<<endl;
    return 0;
}