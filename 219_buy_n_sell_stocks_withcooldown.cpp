#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int helper(int index,int buy,vector<int>& prices,vector<vector<int>>& dp,int n){
    if(index >= n) return 0;
    if(dp[index][buy] != -1) return dp[index][buy];
    int profit = INT_MIN;
    if(buy){
        profit = max((-prices[index] + helper(index + 1,0,prices,dp,n)),
        helper(index+1,1,prices,dp,n));
    }
    else{
        profit = max((prices[index] + helper(index+2,1,prices,dp,n)),
    helper(index+1,0,prices,dp,n));
    }
    return dp[index][buy] = profit;
}
int BuyNSellStocksWithCoolDownMEMO(vector<int>& prices){
    int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return helper(0,1,prices,dp,n);
}
int BuyNSellStocksWithCoolDownTabulation(vector<int>& prices){
    int n = prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,0));//because we uses ind+2
    for(int ind = n-1;ind >= 0;ind--){
        for(int buy = 0;buy <= 1;buy++){
            if(buy){
                dp[ind][buy] = max((-prices[ind] + dp[ind+1][0]),dp[ind+1][1]);
            }
            else dp[ind][buy] = max((prices[ind] + dp[ind+2][1]),dp[ind+1][0]);
        }
    }
    return dp[0][1];
}
int main(){
    vector<int> prices = {4,9,0,4,10};
    int maxProfit = BuyNSellStocksWithCoolDownMEMO(prices);
    cout<<"Cooldown means cant buy after selling immediately!!"<<endl;
    cout<<"Max Profit: "<<maxProfit<<endl;
    int maxProfit1 = BuyNSellStocksWithCoolDownTabulation(prices);
    cout<<"Max Profit: "<<maxProfit1<<endl;
    return 0;
}