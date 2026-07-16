#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class DisjointSet{
public:
    vector<int> size, parent;

    DisjointSet(int n){
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUpar(int u){
        if(u == parent[u]) return u;
        return parent[u] = findUpar(parent[u]);
    }

    void UnionBySize(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int maxRemove(vector<vector<int>>& stones, int n) {
    int maxRow = 0;
    int maxCol = 0;
    for (auto it : stones) {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }
    DisjointSet ds(maxRow + maxCol + 1);
    unordered_map<int, int> stoneNodes;
    for (auto it : stones) {
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;
        ds.UnionBySize(nodeRow, nodeCol);
        stoneNodes[nodeRow] = 1;
        stoneNodes[nodeCol] = 1;
    }
    int cnt = 0;
    for (auto it : stoneNodes) {
        if (ds.findUpar(it.first) == it.first) cnt++;
    }
    return n - cnt;
}
int main(){
    vector<vector<int>> stones = {{0,0},{0,2},{1,3},{3,1},{3,2},{4,3}};
    int n = 6;
    int maxStone = maxRemove(stones,n);
    cout<<"Maximum Stones that can be removed is: "<<maxStone<<endl;
    return 0;
}