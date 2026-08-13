#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int helper(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = 1e8;
    for(int k = i;k <= j;k++){
        int cost = cuts[j+1] - cuts[i-1] + helper(i,k-1,cuts,dp) + helper(k+1,j,cuts,dp);
        mini = min(mini,cost);
    }
    return dp[i][j] = mini;
}
int MinCostCutStickMemo(vector<int> cuts,int LengthOfStick){
    cuts.insert(cuts.begin(),0);
    cuts.push_back(LengthOfStick);
    int n = cuts.size();
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return helper(1,n-2,cuts,dp);
}
int MinCostCutStickTabulation(vector<int> cuts,int LengthOfStick){
    cuts.insert(cuts.begin(),0);
    cuts.push_back(LengthOfStick);
    int n = cuts.size();
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i = n-2;i >= 1;i--){
        for(int j = i;j <= n-2;j++){
            int mini = 1e8;
            for(int k = i;k <= j;k++){
                int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                mini = min(mini,cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n-2];
}
int main(){
    vector<int> cuts = {1,3,4,5};
    int lengthOfStick = 7;
    int MinCost = MinCostCutStickMemo(cuts,lengthOfStick);
    cout<<"Problem Statement: refer leetcode 1547"<<endl;
    cout<<MinCost<<endl;
    int MinCost1 = MinCostCutStickTabulation(cuts,lengthOfStick);
    cout<<MinCost1<<endl;
    return 0;
}