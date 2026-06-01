#include<iostream>
#include<vector>
using namespace std;
void printMatrice(vector<vector<int>> &arr){
    for(int i =0;i < arr.size();i++){
        for(int j = 0;j < arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansrow;
    ansrow.push_back(ans);
    for(int col = 1;col < row;col++){
        ans = ans * (row - col);
        ans = ans / (col);
        ansrow.push_back(ans);
    }
    return ansrow;
}
vector<vector<int>> PascalTriangle(int n){
    vector<vector<int>> answer;
    for(int i = 1;i <= n;i++){
        vector<int> ans = generateRow(i);
        answer.push_back(ans);
    }
    return answer;
}

int main(){
    cout<<"Enter the no of rows for Pascal Triangle: ";
    int n;
    cin >> n;
    vector<vector<int>> answer = PascalTriangle(n);
    printMatrice(answer);
    return 0;
}