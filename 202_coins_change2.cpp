#include<iostream>
#include<vector>
using namespace std;
int helper(int index,int sum,vector<int>& arr,vector<vector<int>>& dp){
    if(index == 0){
        if(sum % arr[index] == 0) return 1;
        else return 0;
    }
    if(dp[index][sum] != -1) return dp[index][sum];
    int notpick = helper(index-1,sum,arr,dp);
    int pick = 0;
    if(arr[index] <= sum) pick = helper(index,sum - arr[index],arr,dp);
    return dp[index][sum] = pick + notpick;
}
int CoinsChange2Memo(vector<int>& arr,int target){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(target + 1,-1));
    return helper(n-1,target,arr,dp);
}
int CoinsChange2Tabulation(vector<int>& arr,int target){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(target + 1,0));
    for(int i = 0;i < n;i++) dp[i][0] = 1;
    for(int t = 0;t <= target;t++) if(t % arr[0] == 0) dp[0][t] = 1;
    for(int ind = 1;ind < n;ind++){
        for(int t = 0;t <= target;t++){
            int notpick = dp[ind-1][t];
            int pick = 0;
            if(arr[ind] <= t) pick = dp[ind][t - arr[ind]];
            dp[ind][t] = notpick + pick;
        }
    }
    return dp[n-1][target];
}
int CoinsChange2Optimised(vector<int>& arr,int target){
    int n = arr.size();
    vector<int> dp(target + 1,0);
    for(int t = 0;t <= target;t++) if(t % arr[0] == 0) dp[t] = 1;
    for(int ind = 1;ind < n;ind++){
        for(int t = arr[ind];t <= target;t++){
            dp[t] += dp[t-arr[ind]];
        }
    }
    return dp[target];
}
int main(){
    vector<int> arr = {1,2,3};
    int target = 4;
    int Ways = CoinsChange2Memo(arr,target);
    cout<<"Number of ways to Form Target "<<target<<" is: "<<Ways<<endl;
    int Ways1 = CoinsChange2Tabulation(arr,target);
    cout<<"Number of ways to Form Target "<<target<<" is: "<<Ways1<<endl;
    int Ways2 = CoinsChange2Optimised(arr,target);
    cout<<"Number of ways to Form Target "<<target<<" is: "<<Ways2<<endl;
    return 0;
}