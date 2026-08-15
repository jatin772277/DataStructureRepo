#include<iostream>
#include<string>
#include<vector>
using namespace std;
int helper(int i,int j,int isTrue,string& str,vector<vector<vector<int>>>& dp){
    if(i > j) return 0;
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    if(i == j){
        if(isTrue) return str[i] == 'T';
        else return str[i] == 'F';
    }
    int ways = 0;
    for(int ind = i + 1;ind < j;ind += 2){
        int lt = helper(i,ind-1,1,str,dp);
        int lf = helper(i,ind-1,0,str,dp);
        int rt = helper(ind+1,j,1,str,dp);
        int rf = helper(ind+1,j,0,str,dp);
        if(str[ind] == '&'){
            if(isTrue) ways += (rt * lt);
            else ways += (rt * lf) + (lt * rf) + (lf * rf);
        }
        else if(str[ind] == '|'){
            if(isTrue) ways += (lt * rf) + (rt * lf) + (lt * rt);
            else ways += (rf * lf); 
        }
        else if(str[ind] == '^'){
            if(isTrue) ways += (lf * rt) + (lt * rf);
            else ways += (lt * rt) + (lf * rf);
        }
    }
    return dp[i][j][isTrue] = ways;
}
int EvaluateBooleanExpressionTrueMemo(string expression){
    int n = expression.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    return helper(0,n-1,1,expression,dp);
}
int EvaluateBooleanExpressionTrueTabulation(string expression){
    int n = expression.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));
    for(int i = 0;i < n;i++){
        if(expression[i] == 'T') dp[i][i][1] = 1;
        else dp[i][i][0] = 1;
    }

    for(int i = n - 1;i >= 0;i--){
        for(int j = i + 1;j < n;j++){
            for(int isTrue = 0;isTrue <= 1;isTrue++){
                int ways = 0;
                for(int ind = i + 1;ind < j;ind += 2){
                    int lt = dp[i][ind-1][1];
                    int lf = dp[i][ind-1][0];
                    int rt = dp[ind+1][j][1];
                    int rf = dp[ind+1][j][0];
                    if(expression[ind] == '&'){
                        if(isTrue) ways += (lt * rt);
                        else ways += (lt * rf) + (lf * rt) + (lf * rf);
                        
                    }
                    else if(expression[ind] == '|'){
                        if(isTrue) ways += (lt * rf) + (lf * rt) + (lt * rt);
                        else ways += (lf * rf);
                        
                    }
                    else if(expression[ind] == '^'){
                        if(isTrue) ways += (lf * rt) + (lt * rf);
                        else ways += (lt * rt) + (lf * rf);
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][n-1][1];
}
int main(){
    string expression = "T^F|T&F^T|F";
    int totalWays = EvaluateBooleanExpressionTrueMemo(expression);
    cout<<"Total Ways to make expression to True: "<<totalWays<<endl;
    int totalWays1 = EvaluateBooleanExpressionTrueTabulation(expression);
    cout<<"Total Ways to make expression to True: "<<totalWays1<<endl;
    return 0;
}