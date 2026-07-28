#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int helper(int index,int target,vector<int>& arr,vector<vector<int>>& dp){
    if(index == 0){
        if(target % arr[index] == 0) return dp[0][target] = target / arr[index];
        else return 1e9;
    }
    if(dp[index][target] != -1) return dp[index][target];
    int nottake = 0 + helper(index-1,target,arr,dp);
    int take = INT_MAX;
    if(arr[index] <= target) take = 1 + helper(index,target - arr[index],arr,dp);
    return dp[index][target] = min(take,nottake);
}
int CoinsChangeMemo(vector<int>& arr,int target){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return helper(n-1,target,arr,dp);
}
int CoinsChangeTabulation(vector<int>& arr,int target){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    for(int t = 0; t <= target; t++){
        if(t % arr[0] == 0)
            dp[0][t] = t / arr[0];
        else
            dp[0][t] = 1e9;
    }
    for(int ind = 1;ind < n;ind++){
        for(int t = 0;t <= target;t++){
            int nottake = 0 + dp[ind-1][t];
            int take = INT_MAX;
            if(arr[ind] <= t) take = 1 + dp[ind][t - arr[ind]];
            dp[ind][t] = min(take,nottake);
        }
    }
    if(dp[n-1][target] >= 1e9) return -1;
    return dp[n-1][target];
}
int main(){
    vector<int> arr = {1,2,3};
    int target = 16;
    int minCoins = CoinsChangeMemo(arr,target);
    cout<<"Minimum Coins to Form target "<<target<<" is: "<<minCoins<<endl;
    int minCoins1 = CoinsChangeTabulation(arr,target);
    cout<<"Minimum Coins to Form target "<<target<<" is: "<<minCoins1<<endl;
    return 0;
}