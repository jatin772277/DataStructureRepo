#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
vector<int> LongestIncresingSubsequenceOptimizedApproach(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n,1);
    for(int i = 0;i < n;i++){
        for(int prev = 0;prev < i;prev++){
            if(arr[prev] < arr[i]) dp[i] = max(dp[i],1 + dp[prev]);
        }
    }
    return dp;
}
int LongestBitonicSubsequence(vector<int>& arr){
    int ans = INT_MIN;
    vector<int> dp1 = LongestIncresingSubsequenceOptimizedApproach(arr);
    reverse(arr.begin(),arr.end());
    vector<int> dp2 = LongestIncresingSubsequenceOptimizedApproach(arr);
    vector<int> bitonic;
    for(int i = 0;i < dp1.size();i++){
        bitonic.push_back(dp1[i] + dp2[i] - 1);
        ans = max(ans,dp1[1] + dp2[i] - 1);
    }
    return ans;
}
int main(){
    vector<int> arr = {1,11,2,10,4,5,2,1};
    int len = LongestBitonicSubsequence(arr);
    cout<<"Bitonic: increasing and then  decreasing and vice versa!!"<<endl;
    cout<<"Longest Bitonic Subsequence: "<<len<<endl;
    return 0;
}