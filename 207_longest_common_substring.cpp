#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int LongestCommonSubstring(string& str1,string &str2){
    int m = str1.size();
    int n = str2.size();
    int ans = INT_MIN;
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return ans;
}
int main(){
    string str1 = "abcjklp";
    string str2 = "acjkp";
    int len = LongestCommonSubstring(str1,str2);
    cout<<"Length of Longest Common Substring: "<<len<<endl;
    return 0;
}