#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int row,int col,vector<string>& board,int n){
    int duprow = row,dupcol = col;
    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }
    row = duprow;
    col = dupcol;
    while(col >= 0){
        if(board[row][col] == 'Q') return false;
        col--;
    }
    row = duprow;
    col = dupcol;
    while(row < n && col >= 0){
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }
    return true;
}
void helper(int col,vector<vector<string>>& result,vector<string>& board,int n){
    if(col == n){
        result.push_back(board);
        return;
    }
    for(int row = 0;row < n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col] = 'Q';
            helper(col+1,result,board,n);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> NQueenProblem(int n){
    vector<vector<string>> result;
    string s(n,'.');
    vector<string> board(n);
    for(int i = 0;i < n;i++) board[i] = s;
    helper(0,result,board,n);
    return result;
}
void printAnswer(vector<vector<string>>& ans){
    int n = ans.size();
    int m = ans[0].size();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            for(int k = 0;k < m;k++){
                cout<<ans[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter The size of ChessBoard: ";
    cin>>n;
    cout<<endl;
    if(n < 10){
        vector<vector<string>> ans = NQueenProblem(n);
        printAnswer(ans);
    }
    else cout<<"invalid Input!!"<<endl;
    return 0;
}