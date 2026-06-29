#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int OrangeRott(vector<vector<int>> &graph){
        int n = graph.size();
        int m = graph[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(graph[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = true;
                }
            }
        }
        int time = 0;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t);
            for(int i = 0;i < 4;i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && visited[nrow][ncol] != true && graph[nrow][ncol] == 1){
                    q.push({{nrow,ncol},t + 1});
                    visited[nrow][ncol] = true;
                }
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(visited[i][j] != true && graph[i][j] == 1) return -1;
            }
        }
        return time;
}
int main(){
    vector<vector<int>> graph = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    int time = OrangeRott(graph);
    cout<<"Time Taken For rotting the oranges: "<<time<<endl;
    cout<<"If It's -1 then all oranges can't be rotted!!!!"<<endl;
    return 0;
}