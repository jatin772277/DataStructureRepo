#include<iostream>
#include<vector>
using namespace std;
int helper(int i,int j,vector<int>& stones,vector<vector<int>>& dp,int sum){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    int left = 0;
    for(int k = i;k < j;k++){
        left += stones[k];
        int right = sum - left;
        if(left < right) ans = max(ans,left + helper(i,k,stones,dp,left));
        else if(left > right) ans = max(ans,right + helper(k+1,j,stones,dp,right));
        else ans = max(ans,left + max(helper(i,k,stones,dp,left) , helper(k+1,j,stones,dp,right)));
    }
    return dp[i][j] = ans;
}
int StoneGame5Memo(vector<int> stones){
    int n = stones.size();
    int sum = 0;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int x : stones) sum += x;
    return helper(0,n-1,stones,dp,sum);
}
int StoneGame5Tabulation(vector<int> stones){
    int n = stones.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    vector<int> prefix(n+1,0);
    for(int i = 0;i < n;i++) prefix[i+1] = prefix[i] + stones[i];
    for(int len = 2;len <= n;len++){
        for(int i = 0;i + len - 1 < n;i++){
            int j = i + len - 1;
            int sum = prefix[j+1] - prefix[i];
            int left = 0;
            for(int k = i;k < j;k++){
                left = prefix[k+1] - prefix[i];
                int right = sum - left;
                if(left < right) dp[i][j] = max(dp[i][j],left + dp[i][k]);
                else if(left > right) dp[i][j] = max(dp[i][j],right + dp[k+1][j]);
                else dp[i][j] = max(dp[i][j],left + max(dp[i][k],dp[k+1][j]));
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    vector<int> stones = {6,2,3,4,5,5};
    int score = StoneGame5Memo(stones);
    cout<<"Alice Score: "<<score<<endl;
    int score1 = StoneGame5Tabulation(stones);
    cout<<"Alice Score: "<<score1<<endl;
    return 0;
}