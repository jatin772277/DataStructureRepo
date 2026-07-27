#include<iostream>
#include<vector>
using namespace std;
int helper(int ind,int target,vector<int>& arr,vector<vector<int>>& dp){
    if(target == 0) return 1;
    if(ind == 0) dp[0][target] = (arr[ind] == target);
    if(dp[ind][target] != -1) return dp[ind][target];
    int notpick = helper(ind-1,target,arr,dp);
    int pick = 0;
    if(arr[ind] <= target) pick = helper(ind-1,target-arr[ind],arr,dp);
    return pick + notpick;
}
int CountSubsetSumKMemo(vector<int>& arr,int target){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(target + 1,-1));
    return helper(n-1,target,arr,dp);
}
int CountSubsetSumKTabulation(vector<int>& arr,int target){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(target +1,0));
    for(int i  = 0;i < n;i++) dp[i][0] = 1;
    if(arr[0] <= target) dp[0][arr[0]] = 1;
    for(int ind = 1;ind < n;ind++){
        for(int j = 0;j <= target;j++){
            int notpick = dp[ind-1][j];
            int pick = 0;
            if(arr[ind] <= j) pick = dp[ind-1][j-arr[ind]];
            dp[ind][j] = pick + notpick;
        }
    }
    return dp[n-1][target];
}
int main(){
    vector<int> arr = {1,2,2,3,4,5,3,6,3};
    int target = 9;
    int totalSubSequence = CountSubsetSumKMemo(arr,target);
    cout<<"Total SubSequence: "<<totalSubSequence<<endl;
    int totalSubSequence1 = CountSubsetSumKTabulation(arr,target);
    cout<<"Total SubSequence: "<<totalSubSequence1<<endl;
    return 0;
}