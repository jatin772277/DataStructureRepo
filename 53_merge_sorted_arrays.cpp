#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printArrays(vector<int> &arr1,vector<int> &arr2){
    for(int x : arr1) cout<<x<<" ";
    for(int y : arr2) cout<<y<<" ";
    cout<<endl;
}
void MergeSortedArrays(vector<int>& arr1,vector<int> &arr2){
    int maxOfFirst = arr1.size() - 1;
    int minOfSecond = 0;
    while(maxOfFirst >= 0 && minOfSecond < arr2.size() && arr1[maxOfFirst] > arr2[minOfSecond]){
        swap(arr1[maxOfFirst] , arr2[minOfSecond]);
        maxOfFirst--;
        minOfSecond++;
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}
int main(){
    vector<int> arr1 = {1,3,5,7};
    vector<int> arr2 = {0,2,6,8,9};
    cout<<"Before merging: "<<endl;
    printArrays(arr1,arr2);
    MergeSortedArrays(arr1,arr2);
    cout<<"After Merging: "<<endl;
    printArrays(arr1,arr2);
    return 0;
}