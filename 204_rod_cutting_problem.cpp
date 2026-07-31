#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int helper(int index,int rodlength,vector<int>& prices,vector<vector<int>>& dp){
    if(index == 0) return (rodlength * prices[0]);
    if(dp[index][rodlength] != -1) return dp[index][rodlength];
    int notpick = 0 + helper(index-1,rodlength,prices,dp);
    int pick = INT_MIN;
    int len = index + 1;
    if(len <= rodlength) pick = prices[index] + helper(index,rodlength - len,prices,dp);
    return dp[index][rodlength] = max(pick,notpick);
}
int RodCuttingMemo(vector<int>& prices,int rodlength){
    int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(rodlength+1,-1));
    return helper(n-1,rodlength,prices,dp);
}
int RodCuttingTabulation(vector<int>& prices,int rodlength){
    int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(rodlength+1,0));
    for(int len = 0;len <= rodlength;len++) dp[0][len] = prices[0] * len;
    for(int ind = 1;ind < n;ind++){
        for(int len = 0;len <= rodlength;len++){
            int notpick = dp[ind-1][len];
            int pick = INT_MIN;
            int rod = ind + 1;
            if(rod <= len) pick = prices[ind] + dp[ind][len - rod];
            dp[ind][len] = max(pick , notpick);
        }
    }
    return dp[n-1][rodlength];
}
int RodCuttingSpaceOptimized(vector<int>& prices,int rodlength){
    int n = prices.size();
    vector<int> dp(rodlength +1,0);
    for(int i = 0;i <= rodlength;i++) dp[i] = prices[0] * i;
    for(int ind = 1;ind < n;ind++){
        int rod = ind + 1;
        for(int len = rod;len <= rodlength;len++){
            dp[len] = max(dp[len], prices[ind] + dp[len - rod]);
        }
    }
    return dp[rodlength];
}
int main(){
    vector<int> prices = {2,5,7,8,10};
    int rodlength = 5;
    cout<<"length 1 rod have price according to price array!!!!!!"<<endl;
    int maxPrice = RodCuttingMemo(prices,rodlength);
    cout<<"Max Price we can Get: "<<maxPrice<<endl;
    int maxPrice1 = RodCuttingTabulation(prices,rodlength);
    cout<<"Max Price we can Get: "<<maxPrice1<<endl;
    int maxPrice2 = RodCuttingSpaceOptimized(prices,rodlength);
    cout<<"Max Price we can Get: "<<maxPrice2<<endl;    
    return 0;
}