#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printArray(vector<int> &arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}
void moveZeroToEnd(vector<int> &arr){
    int j = -1;
    for(int i = 0;i < arr.size();i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    if(j == -1) return;
    for(int i = 1;i < arr.size();i++){
        if(arr[i] != 0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}
int main(){
    vector<int> arr = {1,0,2,3,5,3,0,3,0,2,3,0,7};
    int d = 27;
    printArray(arr);
    moveZeroToEnd(arr);
    printArray(arr);
    return 0;
}