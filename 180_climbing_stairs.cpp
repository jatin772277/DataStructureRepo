#include<iostream>
#include<vector>
using namespace std;
int helper(int n,vector<int> &dp){
    if(n <= 2) return dp[n] = n;
    if(dp[n] != -1) return dp[n];
    else{
        dp[n] = helper(n-1,dp) + helper(n-2,dp);
    }
    return dp[n];
}
int ClimbingStairWays(int n){
    vector<int> dp(n+1,-1);
    return helper(n,dp);
}
int main(){
    int n = 10;
    int totalways = ClimbingStairWays(n);
    cout<<"Total Wayss: "<<totalways<<endl;
    return 0;
}