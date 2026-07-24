#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
    int n = grid.size();
    if(j < 0 || j >= n) return -1e9;
    if(i == 0) return grid[0][j];
    if(dp[i][j] != -1) return dp[i][j];
    int up = helper(i-1,j,grid,dp);
    int ld = helper(i-1,j-1,grid,dp);
    int rd = helper(i-1,j + 1,grid,dp);
    return dp[i][j] = grid[i][j] + max(up,max(ld,rd));
}
int MaxFallingPathSumMemo(vector<vector<int>>& grid){
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = INT_MIN;
    for (int j = 0; j < n; j++) {
        ans = max(ans, helper(n-1, j, grid, dp));
    }
    return ans;
}
int MaxFallingPathSumTabulation(vector<vector<int>>& grid){
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++) dp[0][j] = grid[0][j];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int up = dp[i - 1][j];
            int ld = (j > 0) ? dp[i - 1][j - 1] : -1e9;
            int rd = (j < n - 1) ? dp[i - 1][j + 1] : -1e9;
            dp[i][j] = grid[i][j] + max(up,max(ld,rd));
        }
    }
    int ans = INT_MIN;
    for (int j = 0; j < n; j++) ans = max(ans, dp[n - 1][j]);
    return ans;
}
int main(){
    vector<vector<int>> grid = {
        {1,2,10,4},
        {100,3,2,1},
        {1,1,20,2},
        {1,2,2,1}
    };
    int maxPath = MaxFallingPathSumMemo(grid);
    cout<<"max Path from any starting point to any ending point: "<<maxPath<<endl;
    int maxPath1 = MaxFallingPathSumTabulation(grid);
    cout<<"max Path from any starting point to any ending point: "<<maxPath1<<endl;
    return 0;
}