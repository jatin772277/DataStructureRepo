#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int MinimumEffortPath(const vector<vector<int>>& grid){
    int n = grid.size(),m = grid[0].size();
    vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>
    > pq;
    pq.push({0,{0,0}});
    distance[0][0] = 0;
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    while(!pq.empty()){
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        int diff = pq.top().first;
        pq.pop();
        if(diff > distance[row][col]) continue;
        if(row == n-1 && col == m-1) return diff;
        for(int i = 0;i < 4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                int newEffort = max(abs(grid[row][col] - grid[nrow][ncol]),diff);
                if(newEffort < distance[nrow][ncol]){
                    distance[nrow][ncol] = newEffort;
                    pq.push({newEffort,{nrow,ncol}});
                }
            }
        }
    }
    return 0;
}
int main(){
    vector<vector<int>> grid = {
        {1,2,2},
        {3,8,2},
        {5,3,5}
    };
    int effort = MinimumEffortPath(grid);
    cout<<"From (0,0) to (bottom right point) in this path Minimum Effort: "<<effort<<endl;
    return 0;
    return 0;
}