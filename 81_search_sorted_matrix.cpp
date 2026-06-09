#include<iostream>
#include<vector>
using namespace std;
bool SearchSortedMatrix(vector<vector<int>> &mat,int target){
    bool answer = false;
    int m = mat.size(),n = mat[0].size();
    for(int i = 0;i < mat.size();i++){
        if(mat[i][0] <= target && target <= mat[i][n - 1]){
            int low = 0,high = n - 1;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(mat[i][mid] == target) return true;
                else if(mat[i][mid] > target) high = mid - 1;
                else low = mid + 1;
            }
        }
    }
    return answer;
}
int main(){
    vector<vector<int>> mat = {
        {3,4,7,9},
        {12,13,16,18},
        {20,21,23,29}
    };
    int target = 23;
    bool answer = SearchSortedMatrix(mat,target);
    if(answer) cout<<"Element Found in Matrix!!!!"<<endl;
    else cout<<"Element Not Found in Matrix!!!!"<<endl;
    return 0;
}