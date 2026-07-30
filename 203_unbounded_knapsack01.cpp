#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int helper(int index,int W,vector<int>& weight,vector<int>& value,vector<vector<int>>& dp){
    if(index == 0) return (W / weight[0]) * value[0];
    if(dp[index][W] != -1) return dp[index][W];
    int notpick = helper(index-1,W,weight,value,dp);
    int pick = INT_MIN;
    if(weight[index] <= W) pick = value[index] + helper(index,W-weight[index],weight,value,dp);
    return dp[index][W] = max(pick , notpick);
}
int UnboundedKnapSack01Memo(vector<int>& weight,vector<int>& value,int capacity){
    int n = weight.size();
    vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
    return helper(n-1,capacity,weight,value,dp);
}
int UnboundedKnapSack01Tabulation(vector<int>& weight,vector<int>& value,int capacity){
    int n = weight.size();
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));
    for (int W = 0; W <= capacity; W++) dp[0][W] = (W / weight[0]) * value[0];
    for(int ind = 1;ind < n;ind++){
        for(int W = 0;W <= capacity;W++){
            int notpick = 0 + dp[ind-1][W];
            int pick = INT_MIN;
            if(weight[ind] <= W) pick = value[ind] + dp[ind][W - weight[ind]];
            dp[ind][W] = max(pick,notpick);
        }
    }
    return dp[n-1][capacity];
}
int UnboundedKnapSack01SpaceOptimized(vector<int>& weight, vector<int>& value, int capacity) {
    int n = weight.size();

    vector<int> dp(capacity + 1, 0);

    for (int W = 0; W <= capacity; W++)
        dp[W] = (W / weight[0]) * value[0];

    for (int ind = 1; ind < n; ind++) {
        for (int W = weight[ind]; W <= capacity; W++) {
            dp[W] = max(dp[W], value[ind] + dp[W - weight[ind]]);
        }
    }

    return dp[capacity];
}
int main(){
    vector<int> weight = {2,4,6};
    vector<int> value = {5,11,13};
    int capacity = 10;
    int maxProfit = UnboundedKnapSack01Memo(weight,value,capacity);
    cout<<"Maximum Profit can be: "<<maxProfit<<endl;
    int maxProfit1 = UnboundedKnapSack01Tabulation(weight,value,capacity);
    cout<<"Maximum Profit can be: "<<maxProfit1<<endl;
    int maxProfit2 = UnboundedKnapSack01SpaceOptimized(weight,value,capacity);
    cout<<"Maximum Profit can be: "<<maxProfit2<<endl;
    return 0;
}