#include<iostream>
#include<vector>
using namespace std;
void dfs(int row,int col,vector<vector<bool>>& visited,vector<vector<char>> board
    ,int delrow[],int delcol[]){
        visited[row][col] = true;
        int m = board.size(),n = board[0].size();
        for(int i = 0;i < 4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && 
            !visited[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow,ncol,visited,board,delrow,delcol);
            }
        }
}
    void SurroundedRegion(vector<vector<char>>& board) {
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        int m = board.size(),n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i = 0;i < n;i++){
            if(!visited[0][i] && board[0][i] == 'O'){
                dfs(0,i,visited,board,delrow,delcol);
            }
            if(!visited[m - 1][i] && board[m-1][i] == 'O'){
                dfs(m-1,i,visited,board,delrow,delcol);
            }
        }
        for(int i = 0;i < m;i++){
            if(!visited[i][0] && board[i][0] == 'O'){
                dfs(i,0,visited,board,delrow,delcol);
            }
            if(!visited[i][n-1] && board[i][n-1] == 'O'){
                dfs(i,n-1,visited,board,delrow,delcol);
            }
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(!visited[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
}
int main(){
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','X','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
        {'X','X','O','O'}
    };
    SurroundedRegion(board);
    cout<<"After Replacing Surrounded O's into X's: "<<endl;
    for(int i = 0;i < board.size();i++){
        for(int j = 0;j < board[0].size();j++) cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}