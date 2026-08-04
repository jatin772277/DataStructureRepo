#include<iostream>
#include<vector>
using namespace std;
int helper(int i,int j,string& str1,string& str2,vector<vector<int>>& dp){
    if(j < 0) return 1;
    if(i < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(str1[i] == str2[j]) return dp[i][j] = helper(i-1,j-1,str1,str2,dp) + helper(i-1,j,str1,str2,dp);
    else return dp[i][j] = helper(i-1,j,str1,str2,dp);
}
int CountDistinctSubsequenceMemo(string& str1,string& str2){
    int n = str1.size(),m = str2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return helper(n-1,m-1,str1,str2,dp);
}
int CountDistinctSubsequenceTabulation(string& str1,string& str2){
    int n = str1.size(),m = str2.size();
    vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));
    for(int i = 0;i <= n;i++) dp[i][0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][m];
}
int CountDistinctSubsequenceSpaceOptimized(string& str1,string& str2){
    int n = str1.size(),m = str2.size();
    vector<int> prev(m + 1,0),curr(m+1,0);
    prev[0] = curr[0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(str1[i-1] == str2[j-1]) curr[j] = prev[j-1] + prev[j];
            else curr[j] = prev[j];
        }
        prev = curr;
    }
    return prev[m];
}
int main(){
    string str1 = "babgbag";
    string str2 = "bag";
    int ways = CountDistinctSubsequenceMemo(str1,str2);
    cout<<"distinct subsequences of str1 which equals str2."<<endl;
    cout<<"Ways: "<<ways<<endl;
    int ways1 = CountDistinctSubsequenceTabulation(str1,str2);
    cout<<"distinct subsequences of str1 which equals str2."<<endl;
    cout<<"Ways: "<<ways1<<endl;
    int ways2 = CountDistinctSubsequenceSpaceOptimized(str1,str2);
    cout<<"distinct subsequences of str1 which equals str2."<<endl;
    cout<<"Ways: "<<ways2<<endl;
    return 0;
}