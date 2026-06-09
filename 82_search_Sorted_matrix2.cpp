#include<iostream>
#include<vector>
using namespace std;
pair<int,int> SearchSortedMatrix(vector<vector<int>> &mat,int target){
    pair<int,int> pii = {-1,-1};
    int m = mat.size();
    int n = mat[0].size();
    int row = 0,col = n - 1;
    while(row < m && col >= 0){
        if(mat[row][col] == target) return {row,col};
        else if(mat[row][col] < target) row++;
        else col--;
    }
    return pii;
}
int main(){
    vector<vector<int>> mat = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int target = 23;
    pair<int,int> pii = SearchSortedMatrix(mat,target);
    cout<<"Target found And index: "<<pii.first<<" , "<<pii.second<<endl;
    cout<<"-1,-1 means doesnot exist"<<endl;
    return 0;
}