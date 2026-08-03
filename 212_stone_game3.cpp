#include <bits/stdc++.h>
using namespace std;
class Solution {
    int helper(int ind,vector<int>& stoneValue,vector<int>& dp,int n){
        if(ind == n) return 0;
        if(dp[ind] != -1) return dp[ind];
        dp[ind] = stoneValue[ind] - helper(ind+1,stoneValue,dp,n);
        if(ind + 1 < n){
            dp[ind] = max(dp[ind],stoneValue[ind] + stoneValue[ind + 1]
             - helper(ind + 2,stoneValue,dp,n));
        }
        if(ind + 2 < n){
            dp[ind] = max(dp[ind],
            stoneValue[ind] + stoneValue[ind+1] + stoneValue[ind+2] - 
            helper(ind+3,stoneValue,dp,n));
        }
        return dp[ind];
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1,-1);
        int diff = helper(0,stoneValue,dp,n);
        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";
        else return "Tie";
    }
};
int main() {
    Solution obj;
    vector<int> stoneValue = {1, 2, 3, 7};
    cout << obj.stoneGameIII(stoneValue) << '\n';
    return 0;
}