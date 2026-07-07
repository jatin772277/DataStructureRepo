#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int ShortestDistInGrid(const vector<vector<int>>& grid,pair<int,int> source,pair<int,int> dest){
    int n = grid.size(),m = grid[0].size();
    queue<pair<int,pair<int,int>>> q;
    vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
    distance[source.first][source.second] = 0;
    q.push({0,{source.first,source.second}});
    while(!q.empty()){
        int row = q.front().second.first;
        int col = q.front().second.second;
        int dist = q.front().first;
        q.pop();
        for(int delrow = -1;delrow <= 1;delrow++){
            for(int delcol = -1;delcol <= 1;delcol++){
                if(delrow == 0 && delcol == 0) continue;
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && grid[nrow][ncol] == 1 && dist + 1 < distance[nrow][ncol]){
                    distance[nrow][ncol] = dist + 1;
                    if(nrow == dest.first && ncol == dest.second) return dist + 1;
                    q.push({dist + 1,{nrow,ncol}});
                }
            }
        }
    }
    return -1;
}
int main(){
    vector<vector<int>> grid = {
        {1,1,1,1},
        {1,1,0,1},
        {1,1,1,1},
        {1,1,0,0},
        {1,0,0,0}
    };
    pair<int,int> src = {0,1},destination = {2,3};
    int distance = ShortestDistInGrid(grid,src,destination);
    cout<<"Shortest Between source and Destination is: "<<distance<<endl;
    return 0;
}