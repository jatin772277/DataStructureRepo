#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> CalcDistanceWith1(const vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    vector<vector<int>> result(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(grid[i][j] == 1){
                q.push({{i,j},0});
                visited[i][j] = true;
            }
        }
    }
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int step = q.front().second;
        q.pop();
        result[row][col] = step;
        for(int k = 0;k < 4;k++){
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol]){
                visited[nrow][ncol] = true;
                q.push({{nrow,ncol},step + 1});
            }
        }
    }
    return result;
}
int main(){
    vector<vector<int>> grid = {
        {0,0,0},
        {0,1,0},
        {1,0,1}
    };
    vector<vector<int>> NearDist1 = CalcDistanceWith1(grid);
    cout<<"Every Element's distance with 1: "<<endl;
    for(int i = 0;i < NearDist1.size();i++){
        for(int j = 0;j < NearDist1[0].size();j++) cout<<NearDist1[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}