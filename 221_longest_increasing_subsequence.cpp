#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int helper(int ind,int prev_ind,vector<int>& arr,vector<vector<int>>& dp,int n){
    if(ind == n) return 0;
    if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
    int notpick = helper(ind+1,prev_ind,arr,dp,n);
    int pick = INT_MIN;
    if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
        prev_ind = ind;
        pick = 1 + helper(ind+1,prev_ind,arr,dp,n);
    }
    return dp[ind][prev_ind+1] = max(pick,notpick);
}
int LongestIncreasingSubsequenceMemo(vector<int>& arr){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return helper(0,-1,arr,dp,n);
}
int LongestIncreasingSubsequenceTabulation(vector<int>& arr){
    int n = arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i = n-1;i >= 0;i--){
        for(int j = i - 1;j >= -1;j--){
            int notpick = dp[i+1][j+1];
            int pick = INT_MIN;
            if(j == -1 || arr[i] > arr[j]) pick = 1 + dp[i+1][i+1];
            dp[i][j+1] = max(pick,notpick);
        }
    }
    return dp[0][0];
}
int LongestIncreasingSubsequenceSpaceOptimized(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
int LongestIncresingSubsequenceOptimizedApproach(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n,1);
    int maxi = 1;
    for(int i = 0;i < n;i++){
        for(int prev = 0;prev < i;prev++){
            if(arr[prev] < arr[i]) dp[i] = max(dp[i],1 + dp[prev]);
        }
        maxi = max(maxi,dp[i]);
    }
    return maxi;
}
int main(){
    vector<int> arr = {10,9,2,5,3,7,101,18};
    cout<<"LIC Means subsequence is sorted and highest length!!!"<<endl;
    int maxLen = LongestIncreasingSubsequenceMemo(arr);
    cout<<"max Length: "<<maxLen<<endl;
    int maxLen1 = LongestIncreasingSubsequenceTabulation(arr);
    cout<<"max Length: "<<maxLen1<<endl;
    int maxLen2 = LongestIncreasingSubsequenceSpaceOptimized(arr);
    cout<<"max Length: "<<maxLen2<<endl;
    int maxLen3 = LongestIncresingSubsequenceOptimizedApproach(arr);
    cout<<"max Length: "<<maxLen3<<endl;
    return 0;
}