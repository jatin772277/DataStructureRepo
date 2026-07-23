#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int helper(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
    if(row == 0 && col == 0) return dp[0][0] = grid[0][0];
    if(row < 0 || col < 0) return INT_MAX;
    if(dp[row][col] != -1) return dp[row][col];
    int up = INT_MAX, left = INT_MAX;
    if(row > 0){
        int temp = helper(row-1,col,grid,dp);
        if(temp != INT_MAX) up = grid[row][col] + temp;
    }
    if(col > 0){
        int temp = helper(row,col-1,grid,dp);
        if(temp != INT_MAX) left = grid[row][col] + temp;
    }
    return dp[row][col] = min(up,left);
}
int MinimumPathSumMemoization(vector<vector<int>>& grid){
    int m = grid.size(),n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return helper(m-1,n-1,grid,dp);
}
int MinimumPathSumTabulation(vector<vector<int>>& grid){
    int m = grid.size(),n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    dp[0][0] = grid[0][0];
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(i == 0 && j == 0) continue;
            int up = INT_MAX, left = INT_MAX;
            if(i > 0) up = dp[i-1][j] + grid[i][j];
            if(j > 0) left = dp[i][j-1] + grid[i][j];
            dp[i][j] = min(up, left);
        }
    }
    return dp[m-1][n-1];
}
int main(){
    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    int minPathSum = MinimumPathSumMemoization(grid);
    cout<<"Minimum path sum for reaching bottom right of grid from (0,0): "<<minPathSum<<endl;
    int minPathSum1 = MinimumPathSumTabulation(grid);
    cout<<"Minimum path sum for reaching bottom right of grid from (0,0): "<<minPathSum1<<endl;
    return 0;
}