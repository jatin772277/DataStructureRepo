#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int helper(int index, int buy, int cap, vector<int>& prices,
           vector<vector<vector<int>>>& dp, int n) {
    if (cap == 0 || index == n) return 0;
    if (dp[index][buy][cap] != -1) return dp[index][buy][cap];
    if (buy) {
        return dp[index][buy][cap] = max(
            -prices[index] + helper(index + 1, 0, cap, prices, dp, n),
            helper(index + 1, 1, cap, prices, dp, n));
    }
    return dp[index][buy][cap] = max(
        prices[index] + helper(index + 1,1,cap-1,prices,dp,n),
        helper(index + 1,0,cap,prices,dp,n));
}

int BuyNSellStock4Memo(vector<int>& prices, int k) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
    return helper(0,1,k,prices,dp,n);
}

int BuyNSellStock4Tabulation(vector<int>& prices, int k) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
                if (buy) {
                    dp[ind][buy][cap] = max(-prices[ind] + dp[ind + 1][0][cap],dp[ind + 1][1][cap]);
                } else {
                    dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1],dp[ind + 1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][k];
}
int BuyNSellStock4SpaceOptimized(vector<int>& prices, int k) {
    int n = prices.size();
    vector<vector<int>> after(2, vector<int>(k + 1, 0));
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
                if (buy) {
                    curr[buy][cap] = max(
                        -prices[ind] + after[0][cap],
                        after[1][cap]);
                } else {
                    curr[buy][cap] = max(
                        prices[ind] + after[1][cap - 1],
                        after[0][cap]);
                }
            }
        }
        after = curr;
    }
    return after[1][k];
}

int main() {
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;
    cout<<"Memoization: "<<BuyNSellStock4Memo(prices, k)<<endl;
    cout<<"Tabulation: "<<BuyNSellStock4Tabulation(prices, k)<<endl;
    cout<<"Space Optimized: "<<BuyNSellStock4SpaceOptimized(prices, k)<<endl;
    return 0;
}