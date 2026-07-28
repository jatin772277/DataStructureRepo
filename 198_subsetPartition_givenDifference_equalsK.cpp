#include<iostream>
#include<vector>
using namespace std;
int helper(int ind,int sum,vector<int>& arr,vector<vector<int>>& dp){
    if(ind == 0){
        if(sum == 0 && arr[0] == 0) return 2;
        if(sum == 0 || sum == arr[0]) return 1;
        return 0;
    }
    if(dp[ind][sum] != -1) return dp[ind][sum];
    int nottake = helper(ind-1,sum,arr,dp);
    int take = 0;
    if(arr[ind] <= sum) take = helper(ind-1,sum - arr[ind],arr,dp);
    return dp[ind][sum] = take + nottake;
}
int findWays(vector<int>& arr,int target){
    vector<vector<int>> dp(arr.size(),vector<int>(target + 1,-1));
    return helper(arr.size()-1,target,arr,dp);
}
int findWaysTab(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    if (arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if (arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;
    for (int ind = 1; ind < n; ind++) {
        for (int sum = 0; sum <= target; sum++) {
            int nottake = dp[ind - 1][sum];
            int take = 0;
            if (arr[ind] <= sum) take = dp[ind - 1][sum - arr[ind]];
            dp[ind][sum] = take + nottake;
        }
    }
    return dp[n - 1][target];
}
int PartitionSubsetDifferenceEqualsKMemo(vector<int>& arr,int target){
    int totalSum = 0;
    for(int x : arr) totalSum += x;
    if(totalSum - target < 0 || (totalSum - target) % 2 == 1) return 0;
    return findWays(arr,(totalSum - target) / 2);
}
int PartitionSubsetDifferenceEqualsKTabulation(vector<int>& arr,int target){
    int totalSum = 0;
    for(int x : arr) totalSum += x;
    if(totalSum - target < 0 || (totalSum - target) % 2 == 1) return 0;
    return findWaysTab(arr,(totalSum - target) / 2);
}
int main(){
    vector<int> arr = {5,2,2,6,4,8};
    int target = 3;
    int count = PartitionSubsetDifferenceEqualsKMemo(arr,target);
    cout<<"There are such Subsets Count: "<<count<<endl;
    int count1 = PartitionSubsetDifferenceEqualsKTabulation(arr,target);
    cout<<"There are such Subsets Count: "<<count1<<endl;
    return 0;
}