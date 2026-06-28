#include<iostream>
#include<vector>
using namespace std;
void dfs(int sr,int sc,vector<vector<int>>& ans,vector<vector<int>>& src,
    int color,int delrow[],int delcol[],int iniColor){
        ans[sr][sc] = color;
        int n = src.size();
        int m = src[0].size();
        for(int i = 0;i < 4;i++){
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
            && src[nrow][ncol] == iniColor && ans[nrow][ncol] != color){
                dfs(nrow,ncol,ans,src,color,delrow,delcol,iniColor);
            }
        }
}
vector<vector<int>> FloodFillAlgo(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        if(iniColor == color) return image;
        vector<vector<int>> ans = image;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        dfs(sr,sc,ans,image,color,delrow,delcol,iniColor);
        return ans;
    }
int main(){
    vector<vector<int>> image = {
        {1,1,0},
        {1,0,0},
        {0,0,1}
    };

    int sr = 0;
    int sc = 0;
    int color = 2;
    cout<<"After Colouring: "<<endl;
    vector<vector<int>> ans = FloodFillAlgo(image,sr,sc,color);
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}