#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int LongestCommonSubsequence(string &str1,string &str2){
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
int LongestPalindromicSubsequence(string& str){
    string temp = str;
    reverse(temp.begin(),temp.end());
    return LongestCommonSubsequence(temp,str);
}
int main(){
    string str = "bbabcbcab";
    int len = LongestPalindromicSubsequence(str);
    cout<<"Length of Longest Palindromic Subsequence: "<<len<<endl;
    return 0;
}