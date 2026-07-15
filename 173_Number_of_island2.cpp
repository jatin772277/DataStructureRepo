#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
    vector<int> rank,parent;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i = 0;i <= n;i++) parent[i] = i;
    }
    int findUpar(int u){
        if(u == parent[u]) return u;
        return parent[u] = findUpar(parent[u]);
    }
    void UnionByRank(int u,int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
bool isValid(int nrow,int ncol,int n,int m){
    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) return true;
    else return false;
}
vector<int> NumberOfIsland(int n,int m,const vector<vector<int>>& operators){
    DisjointSet ds(n * m);
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    int count = 0;
    vector<int> result;
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    for(auto it : operators){
        int row = it[0];
        int col = it[1];
        if(visited[row][col] == true){
            result.push_back(count);
            continue;
        }
        visited[row][col] = true;
        count++;
        for(int i = 0;i < 4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(isValid(nrow,ncol,n,m)){
                if(visited[nrow][ncol] == true){
                    int nodeNo = row * m + col;
                    int adjNodeNo = nrow * m + ncol;
                    if(ds.findUpar(nodeNo) != ds.findUpar(adjNodeNo)){
                        count--;
                        ds.UnionByRank(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        result.push_back(count);
    }
    return result;
}
int main(){
    vector<vector<int>> operators;
    int n = 4,m = 5;
    operators.push_back({0,0});
    operators.push_back({0,0});
    operators.push_back({1,1});
    operators.push_back({1,0});
    operators.push_back({0,1});
    operators.push_back({0,3});
    operators.push_back({1,3});
    operators.push_back({0,4});
    operators.push_back({3,2});
    operators.push_back({2,2});
    operators.push_back({1,2});
    operators.push_back({0,2});
    vector<int> NumOfIslandProgress = NumberOfIsland(n,m,operators);
    cout<<"Answer: ";
    for(int x : NumOfIslandProgress) cout<<x<<" ";
    cout<<endl;
    return 0;
}