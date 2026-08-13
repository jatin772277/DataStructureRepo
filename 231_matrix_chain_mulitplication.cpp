#include<iostream>
#include<vector>
#include<climits>
using namespace std;
long long helper(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    long long mini = 1e9;
    for(int k = i;k <= (j-1);k++){
        long long steps = arr[i-1] * arr[k] * arr[j]
                    + helper(i,k,arr,dp) + helper(k+1,j,arr,dp);
        mini = min(mini,steps);
    }
    return dp[i][j] = mini;
}
long long MatrixChainMultiplicationMemo(vector<int>& arr){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return helper(1,n-1,arr,dp);
}
long long MatrixChainMultiplicationTabulation(vector<int>& arr){
    int n = arr.size();
    vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
    for(int i = n-1;i >= 1;i--){
        for(int j = i + 1;j < n;j++){
            dp[i][j] = LLONG_MAX;
            for(int k = i;k < j;k++){
                long long steps = 1LL * arr[i-1] * arr[j] * arr[k] + dp[i][k] + dp[k+1][j];
                dp[i][j] = min(dp[i][j],steps);
            }
        }
    }
    return dp[1][n-1];
}
int main(){
    vector<int> arr = {40, 20, 30, 10, 30};
    //A = (40*20) B = (20 * 30) C = (30 * 10) D = (10 * 30)
    long long MinOper = MatrixChainMultiplicationMemo(arr);
    cout<<"Minimum Operations: "<<MinOper<<endl;
    long long MinOper1 = MatrixChainMultiplicationTabulation(arr);
    cout<<"Minimum Operations: "<<MinOper1<<endl;
    return 0;
}