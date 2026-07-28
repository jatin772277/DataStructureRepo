#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int helper(int index,int capacity,vector<int>& values,vector<int>& weights,
vector<vector<int>>& dp){
    if(index == 0){
        if(weights[0] <= capacity) return dp[0][capacity] = values[0];
        else return 0;
    }
    if(dp[index][capacity] != -1) return dp[index][capacity];
    int nottake = 0 + helper(index - 1,capacity,values,weights,dp);
    int take = INT_MIN;
    if(weights[index] <= capacity) 
        take = values[index] + helper(index-1,capacity-weights[index],values,weights,dp);
    return dp[index][capacity] = max(take,nottake);
}
int KnapSack01Memo(vector<int>& values,vector<int>& weights,int capacity){
    int n = values.size();
    vector<vector<int>> dp(n,vector<int>(capacity + 1,-1));
    return helper(n-1,capacity,values,weights,dp);
}
int KnapSack01Tabulation(vector<int>& values,vector<int>& weights,int capacity){
    int n = values.size();
    vector<vector<int>> dp(n,vector<int>(capacity + 1,0));
    for(int i = weights[0];i <= capacity;i++) dp[0][i] = values[0];
    for(int ind = 1;ind < n;ind++){
        for(int wt = 0;wt <= capacity;wt++){
            int nottake = 0 + dp[ind-1][wt];
            int take= INT_MIN;
            if(weights[ind] <= wt) take = values[ind] + dp[ind-1][wt - weights[ind]];
            dp[ind][wt] = max(take,nottake);
        }
    }
    return dp[n-1][capacity];
}
int main(){
    vector<int> values = {6,10,12,18};
    vector<int> weights = {2,2,4,6};
    int capacity = 8;
    int maxval = KnapSack01Memo(values,weights,capacity);
    cout<<"Maximum Thief can Steel: "<<maxval<<endl;
    int maxval1 = KnapSack01Tabulation(values,weights,capacity);
    cout<<"Maximum Thief can Steel: "<<maxval1<<endl;
    return 0;
}