#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int helper(int ind,int buy,vector<int>& prices,vector<vector<int>>& dp,int n){
    if(ind == n) return 0;
    int profit = INT_MIN;
    if(buy) profit = max((-prices[ind] + helper(ind+1,0,prices,dp,n)) , (helper(ind+1,1,prices,dp,n)));
    else profit = max((prices[ind] + helper(ind+1,1,prices,dp,n)) , helper(ind+1,0,prices,dp,n));
    return profit;
}
int BuyNSellStock3Memo(vector<int>& prices){
    int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return helper(0,1,prices,dp,n);
}
int BuyNSellStock3Tabulation(vector<int>& prices){
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for(int ind = n - 1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            if(buy){
                dp[ind][buy] = max(
                    -prices[ind] + dp[ind + 1][0], 
                    dp[ind + 1][1]      
                );
            }
            else{
                dp[ind][buy] = max(
                    prices[ind] + dp[ind + 1][1], 
                    dp[ind + 1][0] 
                );
            }
        }
    }

    return dp[0][1];
}

int main(){
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int maxProfit = BuyNSellStock3Memo(prices);
    cout << "Max Profit (Memoization): " << maxProfit << endl;
    int maxProfit1 = BuyNSellStock3Tabulation(prices);
    cout << "Max Profit (Tabulation): " << maxProfit1 << endl;
    return 0;
}