#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>> findAllPeaks(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<pair<int,int>> ans;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int cur = mat[i][j];
            bool peak =
                (i == 0 || cur > mat[i-1][j]) &&
                (i == n-1 || cur > mat[i+1][j]) &&
                (j == 0 || cur > mat[i][j-1]) &&
                (j == m-1 || cur > mat[i][j+1]);
            if(peak) ans.push_back({i, j});
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> mat = {
        {4,2,5,1,4,5},
        {2,9,3,2,3,2},
        {1,7,6,0,1,3},
        {3,6,2,3,7,2}
    };
    vector<pair<int,int>> pii = findAllPeaks(mat);
    for(int i = 0;i < pii.size();i++){
        cout<<"{"<<pii[i].first<<" , "<<pii[i].second<<"} ";
    }
    cout<<endl;
    return 0;
}