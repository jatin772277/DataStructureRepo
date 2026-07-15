#include <iostream>
#include <vector>
#include <set>
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

class Solution {
    bool isValid(int nrow, int ncol, int n){
        return (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n);
    }

public:
    int largestIsland(vector<vector<int>>& grid){

        int n = grid.size();

        DisjointSet ds(n * n);

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){

                if(grid[row][col] == 0) continue;

                for(int ind = 0; ind < 4; ind++){

                    int nrow = row + delrow[ind];
                    int ncol = col + delcol[ind];

                    if(isValid(nrow, ncol, n) && grid[nrow][ncol] == 1){

                        int nodeNo = row * n + col;
                        int adjNodeNo = nrow * n + ncol;

                        ds.UnionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        int mx = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){

                if(grid[row][col] == 1) continue;

                set<int> components;

                for(int ind = 0; ind < 4; ind++){

                    int nrow = row + delrow[ind];
                    int ncol = col + delcol[ind];

                    if(isValid(nrow, ncol, n) && grid[nrow][ncol] == 1){
                        components.insert(ds.findUpar(nrow * n + ncol));
                    }
                }

                int sizeTotal = 1;

                for(auto it : components){
                    sizeTotal += ds.size[it];
                }

                mx = max(mx, sizeTotal);
            }
        }

        for(int i = 0; i < n * n; i++){
            mx = max(mx, ds.size[ds.findUpar(i)]);
        }

        return mx;
    }
};

int main(){

    Solution obj;

    vector<vector<int>> grid = {
        {1, 1, 0},
        {1, 0, 0},
        {0, 0, 1}
    };

    cout << "Largest Island: " << obj.largestIsland(grid) << endl;

    return 0;
}