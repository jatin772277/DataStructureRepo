#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int helper(int index,int buy,int cap,vector<int>& prices,
vector<vector<vector<int>>>& dp,int n){
    if(cap == 0) return 0;
    if(index == n) return 0;
    if(dp[index][buy][cap] != -1) return dp[index][buy][cap];
    int profit = INT_MIN;
    if(buy){
        profit = 
        max((-prices[index] + helper(index+1,0,cap,prices,dp,n)) , (helper(index+1,1,cap,prices,dp,n)));
    }
    else{
        profit = max((prices[index] + helper(index+1,1,cap-1,prices,dp,n)) , helper(index+1,0,cap,prices,dp,n));
    }
    return dp[index][buy][cap] = profit;
}
int BuyNSellStock3Memo(vector<int>& prices){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return helper(0,1,2,prices,dp,n);
}
int BuyNSellStock3Tabulation(vector<int>& prices){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int ind = n-1;ind >= 0;ind--){
        for(int buy = 0;buy <= 1;buy++){
            for(int cap = 1;cap <= 2;cap++){
                if(buy){
                    dp[ind][buy][cap] = max((-prices[ind] + dp[ind+1][0][cap]),dp[ind+1][1][cap]);
                }
                else{
                    dp[ind][buy][cap] = max((prices[ind] + dp[ind+1][1][cap-1]),dp[ind+1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}
int BuyNSellStock3SpaceOptimized(vector<int>& prices){
    int n = prices.size();
    vector<vector<int>> after(2,vector<int>(3,0));
    vector<vector<int>> curr(2,vector<int>(3,0));
    for(int ind = n-1;ind >= 0;ind--){
        for(int buy = 0;buy <= 1;buy++){
            for(int cap = 1;cap <= 2;cap++){
                if(buy){
                    curr[buy][cap] = max((-prices[ind] + after[0][cap]),after[1][cap]);
                }
                else{
                    curr[buy][cap] = max((prices[ind] + after[1][cap-1]),after[0][cap]);
                }
            }
        }
        after = curr;
    }
    return after[1][2];
}
int main(){
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int maxProfit = BuyNSellStock3Memo(prices);
    cout << "Max Profit (Memoization): " << maxProfit << endl;
    int maxProfit1 = BuyNSellStock3Tabulation(prices);
    cout << "Max Profit (Tabulation): " << maxProfit1 << endl;
    int maxProfit2 = BuyNSellStock3Tabulation(prices);
    cout << "Max Profit (Space Optimized): " << maxProfit2 << endl;
    return 0;
}