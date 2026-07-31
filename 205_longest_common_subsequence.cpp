#include<iostream>
#include<vector>
using namespace std;
int helper(int i,int j,string& str1,string &str2,vector<vector<int>>& dp){
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(str1[i] == str2[j]) return dp[i][j] = 1 + helper(i-1,j-1,str1,str2,dp);
    return dp[i][j] = max(helper(i-1,j,str1,str2,dp) , helper(i,j-1,str1,str2,dp));
}
int LongestCommonSubsequenceLengthMemo(string &str1,string &str2){
    int n1 = str1.size();
    int n2 = str2.size();
    vector<vector<int>> dp(n1,vector<int>(n2,-1));
    return helper(n1-1,n2-1,str1,str2,dp);
}
int LongestCommonSubsequenceLengthTabulation(string &str1,string &str2){
    int n1 = str1.size();
    int n2 = str2.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    for(int i = 1;i <= n1;i++){
        for(int j = 1;j <= n2;j++){
            if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    return dp[n1][n2];
}
int LongestCommonSubsequenceLengthSpaceOptimized(string &str1, string &str2){
    int n1 = str1.size();
    int n2 = str2.size();
    vector<int> prev(n2 + 1, 0), curr(n2 + 1, 0);
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            if(str1[i - 1] == str2[j - 1]) curr[j] = 1 + prev[j - 1];
            else curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[n2];
}
int main(){
    string str1 = "adcbe";
    string str2 = "dcadb";
    int len = LongestCommonSubsequenceLengthMemo(str1,str2);
    cout<<"Length of LCS: "<<len<<endl;
    int len1 = LongestCommonSubsequenceLengthTabulation(str1,str2);
    cout<<"Length of LCS: "<<len1<<endl;
    int len2 = LongestCommonSubsequenceLengthSpaceOptimized(str1,str2);
    cout<<"Length of LCS: "<<len2<<endl;
    return 0;
}