#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// int helper(int index,vector<int>& heights,vector<int>& dp){
//     if(index == 0) return dp[0] = 0;
//     if(dp[index] != -1) return dp[index];
//     int left = helper(index-1,heights,dp) + abs(heights[index] - heights[index - 1]);
//     int right = INT_MAX;
//     if(index > 1) right = helper(index-2,heights,dp) + abs(heights[index] - heights[index - 2]);
//     return dp[index] = min(left,right);
// }
// int FrogJumpMinEnergyLost(vector<int> &heights){//Memoization
//     int n = heights.size();
//     vector<int> dp(n,-1);
//     return helper(n-1,heights,dp);
// }
int FrogJumpMinEnergyLost(vector<int>& heights){//Tabulation
    int n = heights.size();
    vector<int> dp(n,0);
    dp[0] = 0;
    for(int i = 1;i < n;i++){
        int first = dp[i - 1] + abs(heights[i-1] - heights[i]);
        int right = INT_MAX;
        if(i > 1) right = dp[i - 2] + abs(heights[i-2] - heights[i]);
        dp[i] = min(first,right);
    }
    return dp[n-1];
}
int main(){
    vector<int> heights = {30,10,60,10,60,50};
    int minEnergy = FrogJumpMinEnergyLost(heights);
    cout<<"Frog can Reach to end by losing Min Energry: "<<minEnergy<<endl;
    return 0;
}