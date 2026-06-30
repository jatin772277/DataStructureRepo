#include<iostream>
#include<vector>
#include<set>
using namespace std;
void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<bool>>& visited,
    vector<pair<int,int>> &vec,int row0,int col0,int delrow[],int delcol[]){
        visited[row][col] = true;
        int n = grid.size(),m = grid[0].size();
        vec.push_back({row - row0,col - col0});
        for(int i = 0;i < 4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
            && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,grid,visited,vec,row0,col0,delrow,delcol);
            }
        }
}
int NumberOfDistinctIsland(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    set<vector<pair<int,int>>> sett;
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(!visited[i][j] && grid[i][j] == 1){
                vector<pair<int,int>> vec;
                dfs(i,j,grid,visited,vec,i,j,delrow,delcol);
                sett.insert(vec);
            } 
        }
    }
    return sett.size();
}
int main(){
    vector<vector<int>> grid = {
        {1,1,0,1,1},
        {1,0,0,0,0},
        {0,0,0,0,1},
        {1,1,0,1,1}
    };
    int ans = NumberOfDistinctIsland(grid);
    cout<<"Distinct Island: "<<ans<<endl; 
    return 0;
}