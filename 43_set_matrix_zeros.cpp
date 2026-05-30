#include<iostream>
#include<vector>
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
void SetMatrixZeros(vector<vector<int>> &arr){
    int n = arr[0].size();
    int m = arr.size();
    vector<int> markCol(n,0);
    vector<int> markRow(m,0);
    for(int i =0;i < arr.size();i++){
        for(int j = 0;j < arr[0].size();j++){
            if(arr[i][j] == 0){
                markCol[j] = 1;
                markRow[i] = 1;
            }
        }
    }
    for(int i = 0;i < arr.size();i++){
        for(int j =0;j < arr[0].size();j++){
            if(markRow[i] == 0 && markCol[j] == 0) arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
}
int main(){
    vector<vector<int>> arr = {
        {1,1,1,1,1},{1,0,1,1,1},{1,1,0,1,1},{1,1,1,0,1}
    };
    cout<<"Original Matrix: "<<endl;
    printMatrice(arr);
    SetMatrixZeros(arr);
    cout<<"After Applying Function: "<<endl;
    printMatrice(arr);
    return 0;
}