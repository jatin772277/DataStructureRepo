#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printMatrice(vector<vector<int>> &arr){
    for(int i = 0;i < arr.size();i++){
        for(int j =0 ;j < arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void SpiralTraversal(vector<vector<int>> &arr){
    int m = arr.size();
    int n = arr[0].size();
    int top = 0,bottom = m - 1;
    int left = 0,right = n - 1;
    while(top <= bottom && left <= right){
        //right
    for(int i = left;i <= right;i++){
        cout<<arr[top][i]<<" ";
    }
    top++;
    //bottom
    for(int i = top;i <= bottom;i++){
        cout<<arr[i][right]<<" ";
    }
    right--;
    //left
    if(top <= bottom){
        for(int i = right;i >= left;i--){
        cout<<arr[bottom][i]<<" ";
        }
        bottom--;
    }
    //top
    if(left <= right){
        for(int i = bottom;i >= top;i--){
        cout<<arr[i][left]<<" ";
    }
    left++;
    }
    }
}

int main(){
    vector<vector<int>> arr = {
    { 1,  2,  3,  4,  5,  6},
    {20, 21, 22, 23, 24,  7},
    {19, 32, 33, 34, 25,  8},
    {18, 31, 36, 35, 26,  9},
    {17, 30, 29, 28, 27, 10},
    {16, 15, 14, 13, 12, 11}
};
    cout<<"Original Matrix: "<<endl;
    printMatrice(arr);
    cout<<"Spiral Traversal: ";
    SpiralTraversal(arr);
    return 0;
}