#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int i,int j,vector<vector<bool>>& visited,const vector<vector<int>>& graph){
    visited[i][j] = true;
    queue<pair<int,int>> q;
    q.push({i,j});
    int n = graph.size();
    int m = graph[0].size();

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int delrow = -1;delrow <= 1;delrow++){
            for(int delcol = -1;delcol <= 1;delcol++){
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && graph[nrow][ncol] == 1
                && !visited[nrow][ncol]){
                    visited[nrow][ncol] = true;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}
int NumIslandGraph(const vector<vector<int>> &graph){
    int n = graph.size();
    int m = graph[0].size();
    vector<vector<bool>> visited(n , vector<bool>(m,false));
    int count = 0;
    for(int i = 0;i < graph.size();i++){
        for(int j = 0;j < graph[0].size();j++){
            if(!visited[i][j] && graph[i][j] == 1){
                count++;
                bfs(i,j,visited,graph);
            }
        }
    }
    return count;
}
int main(){
    vector<vector<int>> matrix = {
        {0,1,1,0},
        {0,1,1,0},
        {0,0,1,0},
        {0,0,0,0},
        {1,1,0,1}
    };
    int NumIsland = NumIslandGraph(matrix);
    cout<<"Number of Islands: "<<NumIsland<<endl;
    return 0;
}