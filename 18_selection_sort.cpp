#include<iostream>
#include<vector>
using namespace std;
void Selection_Sort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0;i < n-1;i++){
        int minIndex = i;
        for(int j = i+1;j < n;j++){
            if(arr[j] < arr[minIndex]) minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
void printVector(vector<int> &arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> temp = {23,43,17,26,34,22,11};
    printVector(temp);
    Selection_Sort(temp);
    cout<<endl;
    cout<<"Sorted array: ";
    printVector(temp);
    return 0;
}