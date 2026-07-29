#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int targetSum(vector<int>& nums,int target){
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < abs(target) || (sum + target) % 2 != 0) return 0;
    int newTarget = (sum + target) / 2;
    vector<vector<int>> dp(n, vector<int>(newTarget + 1, 0));
    if (nums[0] == 0) dp[0][0] = 2;
    else {
        dp[0][0] = 1;
        if (nums[0] <= newTarget) dp[0][nums[0]] = 1;
    }
    for (int ind = 1; ind < n; ind++) {
        for (int j = 0; j <= newTarget; j++) {
            int notPick = dp[ind - 1][j];
            int pick = 0;
            if (nums[ind] <= j) pick = dp[ind - 1][j - nums[ind]];
            dp[ind][j] = pick + notPick;
        }
    }
    return dp[n - 1][newTarget];
}
int main(){
    vector<int> arr=  {1,2,3,1};
    int target = 3;
    int ways = targetSum(arr,target);
    cout<<"Ways: "<<ways<<endl;
    return 0;
}