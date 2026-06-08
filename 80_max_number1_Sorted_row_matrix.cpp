#include<iostream>
#include<vector>
using namespace std;
int findmax1RowSortedBinaryMatrix(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    int row = 0,col = m - 1;
    int ans = -1;
    while(row < n && col >= 0){
        if(mat[row][col] == 1){
            ans = row;
            col--;
        }
        else row++;
    }
    return ans;
}
int main(){
    vector<vector<int>> mat = {
        {0,0,1,1,1},
        {0,0,0,0,0},
        {0,1,1,1,1},
        {0,0,0,0,0},
        {0,1,1,1,1}
    };
    int row = findmax1RowSortedBinaryMatrix(mat);
    cout<<"Row in which maximum number of 1's exist while matrix is sorted row wise and binary: "<<row<<endl;
    return 0;
}