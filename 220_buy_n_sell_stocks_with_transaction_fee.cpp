#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int helper(int index,int buy,vector<int>& prices,vector<vector<int>>& dp,int n,int fee){
    if(index >= n) return 0;
    if(dp[index][buy] != -1) return dp[index][buy];
    int profit = INT_MIN;
    if(buy){
        profit = max((-prices[index] + helper(index + 1,0,prices,dp,n,fee)),
        helper(index+1,1,prices,dp,n,fee));
    }
    else{
        profit = max((prices[index] + helper(index+1,1,prices,dp,n,fee)) - fee,
    helper(index+1,0,prices,dp,n,fee));
    }
    return dp[index][buy] = profit;
}
int BuyNSellStocksWithTransactionFeeMEMO(vector<int>& prices,int fee){
    int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return helper(0,1,prices,dp,n,fee);
}
int BuyNSellStocksWithTransactionFeeTabulation(vector<int>& prices,int fee){
    int n = prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,0));//because we uses ind+2
    for(int ind = n-1;ind >= 0;ind--){
        for(int buy = 0;buy <= 1;buy++){
            if(buy){
                dp[ind][buy] = max((-prices[ind] + dp[ind+1][0]),dp[ind+1][1]);
            }
            else dp[ind][buy] = max((prices[ind] + dp[ind+1][1] - fee),dp[ind+1][0]);
        }
    }
    return dp[0][1];
}
int main(){
    vector<int> prices = {1,3,2,8,4,9};
    int maxProfit = BuyNSellStocksWithTransactionFeeMEMO(prices,2);
    cout<<"Transaction Fee Means after a buy and sell a fee will be charged!!"<<endl;
    cout<<"Max Profit: "<<maxProfit<<endl;
    int maxProfit1 = BuyNSellStocksWithTransactionFeeTabulation(prices,2);
    cout<<"Max Profit: "<<maxProfit1<<endl;
    return 0;
}