#include<iostream>
#include<vector>
using namespace std;
// int helper(int index,vector<int>& nums,vector<int>& dp){
//     if(index == 0) return dp[0] = nums[0];
//     if(index < 0) return 0;
//     if(dp[index] != -1) return dp[index];
//     int pick = nums[index] + helper(index - 2,nums,dp);
//     int nonPick = 0 + helper(index - 1,nums,dp);
//     return dp[index] = max(pick , nonPick);
// }
// int MaxNonAdjacentSubsequencesSum(vector<int> &nums){//Memoization
//     int n = nums.size();
//     vector<int> dp(n,-1);
//     return helper(n-1,nums,dp);
// }
int MaxNonAdjacentSubsequencesSum(vector<int>& nums){//Tabulation
    int n = nums.size();
    vector<int> dp(n,-1);
    dp[0] = nums[0];
    for(int i = 1;i < n;i++){
        if(i > 1) dp[i] = max((dp[i - 2] + nums[i]),dp[i - 1]);
        else dp[i] = dp[i - 1];
    }
    return dp[n-1];
}
int main(){
    vector<int> nums = {5, 5, 10, 100, 10, 5};
    int sum = MaxNonAdjacentSubsequencesSum(nums);
    cout<<"Sum: "<<sum<<endl;
    return 0;
}