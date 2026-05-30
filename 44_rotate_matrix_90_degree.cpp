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
void RotateMatrix(vector<vector<int>> &arr){
    int m = arr.size();
    int n = arr[0].size();
    for(int i = 0;i < m;i++){
        for(int j = i;j < n;j++){
            if(i != j) swap(arr[i][j] ,arr[j][i]);
            else continue;
        }
    }
    for(int i = 0;i < m;i++){
        reverse(arr[i].begin(),arr[i].end());
    }
}
int main(){
    vector<vector<int>> arr = {
        {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}
    };
    cout<<"Original Matrix: "<<endl;
    printMatrice(arr);
    RotateMatrix(arr);
    cout<<"After Rotating: "<<endl;
    printMatrice(arr);
    return 0;
}