#include<iostream>
#include<vector>
using namespace std;
int helper(int i,int j1,int j2,vector<vector<int>>& cherryboard,
vector<vector<vector<int>>>& dp){
    int m = cherryboard.size();
    int n = cherryboard[0].size();
    if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) return -1e8;
    if(i == m-1){
        if(j1 == j2) return cherryboard[i][j1];
        else return cherryboard[i][j1] + cherryboard[i][j2];
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    int ans = -1e8;
    for(int dj1 = -1;dj1 <= 1;dj1++){
        for(int dj2 = -1;dj2 <= 1;dj2++){
            int value;
            if(j1 == j2) value = cherryboard[i][j1];
            else value = cherryboard[i][j1] + cherryboard[i][j2];
            value += helper(i+1,j1 + dj1,j2 +dj2,cherryboard,dp);
            ans = max(ans,value);
        }
    }
    return dp[i][j1][j2] = ans;
}
int CherryPickUpMemo(vector<vector<int>>& cherryboard){
    int m = cherryboard.size();
    int n = cherryboard[0].size();
    vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
    return helper(0,0,n-1,cherryboard,dp);
}
int CherryPickUpTabulation(vector<vector<int>>& cherryboard){
    int m = cherryboard.size();
    int n = cherryboard[0].size();
    vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
    for(int j1 = 0;j1 < n;j1++){
        for(int j2 = 0;j2 < n;j2++){
            if(j1 == j2) dp[m-1][j1][j2] = cherryboard[m-1][j1];
            else dp[m-1][j1][j2] = cherryboard[m-1][j1] + cherryboard[m-1][j2];
        }
    }
    for(int i = m-2;i >= 0;i--){
        for(int j1 = 0;j1 < n;j1++){
            for(int j2 = 0;j2 < n;j2++){
                int ans = -1e8;
                for(int dj1 = -1;dj1 <= 1;dj1++){
                    for(int dj2 = -1;dj2 <= 1;dj2++){
                        int nj1 = j1 + dj1;
                        int nj2 = j2 + dj2;
                        if(nj1 >= 0 && nj1 < n && nj2 >= 0 && nj2 < n){
                            int value;
                            if(j1 == j2) value = cherryboard[i][j1];
                            else value = cherryboard[i][j1] + cherryboard[i][j2];
                            value += dp[i + 1][nj1][nj2];
                            ans = max(ans,value);
                        }
                    }
                }
                dp[i][j1][j2] = ans;
            }
        }
    }
    return dp[0][0][n-1];
}
int main(){
    vector<vector<int>> cherryboard = {
        {2,3,1,2},
        {3,4,2,2},
        {5,6,3,5}
    };
    int maxcherry = CherryPickUpMemo(cherryboard);
    cout<<"Maximum can be grabbed by alice and bob: "<<maxcherry<<endl;
    int maxcherry1 = CherryPickUpTabulation(cherryboard);
    cout<<"Maximum can be grabbed by alice and bob: "<<maxcherry1<<endl;
    return 0;
}