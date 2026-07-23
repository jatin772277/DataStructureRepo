#include<iostream>
#include<vector>
using namespace std;
int helper(int i,int j,vector<vector<int>>& cells,vector<vector<int>>& dp){
    if(i >= 0 && j >= 0 && cells[i][j] == -1) return 0;
    if(i == 0 && j == 0) return dp[i][j] = 1;
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int up = helper(i-1,j,cells,dp);
    int left = helper(i,j-1,cells,dp);
    return dp[i][j] = (up + left);
}
int UniquePathMemoization(int m,int n,vector<vector<int>>& cells){
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return helper(m-1,n-1,cells,dp);
}
int UniquePathTabulation(int m, int n, vector<vector<int>>& cells){
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(cells[i][j] == -1){
                dp[i][j] = 0;
                continue;
            }
            if(i == 0 && j == 0){
                dp[i][j] = 1;
                continue;
            }
            int up = 0, left = 0;
            if(i > 0) up = dp[i-1][j];
            if(j > 0) left = dp[i][j-1];
            dp[i][j] = up + left;
        }
    }
    return dp[m-1][n-1];
}
int main(){
    int m = 3,n = 3;
    vector<vector<int>> cells = {
        {0,0,0},
        {0,-1,0},
        {0,0,0}
    };
    int uniqueWays = UniquePathMemoization(m,n,cells);
    int uniqueWays1 = UniquePathTabulation(m,n,cells);
    cout<<"Unique Ways For (0,0) to End of grid While Obstacles are there: "<<uniqueWays<<endl;
    cout<<"Unique Ways For (0,0) to End of grid While Obstacles are there: "<<uniqueWays1<<endl;
    return 0;
}