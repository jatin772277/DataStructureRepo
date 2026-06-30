#include<iostream>
#include<vector>
using namespace std;
void dfs(int row,int col,vector<vector<bool>>& visited,vector<vector<int>>& grid,
    int delrow[],int delcol[]){
        visited[row][col] = true;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i < 4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
            && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,visited,grid,delrow,delcol);
            }
        }
    }
    int NumberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        for(int i = 0;i < m;i++){
            if(!visited[0][i] && grid[0][i] == 1){
                dfs(0,i,visited,grid,delrow,delcol);
            }
            if(!visited[n-1][i] && grid[n-1][i] == 1){
                dfs(n-1,i,visited,grid,delrow,delcol);
            }
        }
        for(int i = 0;i < n;i++){
            if(!visited[i][0] && grid[i][0] == 1){
                dfs(i,0,visited,grid,delrow,delcol);
            }
            if(!visited[i][m-1] && grid[i][m-1] == 1){
                dfs(i,m-1,visited,grid,delrow,delcol);
            }
        }
        int count = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!visited[i][j] && grid[i][j] == 1) count++;
            }
        }
        return count;
    }
int main(){
    vector<vector<int>> board = {
        {0,0,0,1},
        {0,1,1,0},
        {0,1,1,0},
        {0,0,0,1},
        {0,1,1,0}
    };
    int enclaves = NumberOfEnclaves(board);
    cout<<"Number of One's that aren't Connected to the boundary directly or indirectly!!: "<<enclaves;
    cout<<endl;
    return 0;
}