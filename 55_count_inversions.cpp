#include<iostream>
#include<vector>
using namespace std;
int merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int count = 0;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else{
            count += (mid - left + 1);
            temp.push_back(arr[right++]);
        }
    }
    while(left <= mid){
        temp.push_back(arr[left++]);
    }
    while(right <= high){
        temp.push_back(arr[right++]);
    }
    for(int i = low;i <= high;i++){
        arr[i] = temp[i - low];
    }
    return count;
}
int mergeSort(vector<int> &arr,int low ,int high){
    if(low >= high) return 0;
    int mid = low + (high - low) / 2;
    int count = 0;
    count += mergeSort(arr,low,mid);
    count += mergeSort(arr,mid + 1,high);
    count += merge(arr,low,mid,high);
    return count;
}
int CountInversion(vector<int> &arr){
    return mergeSort(arr,0,arr.size() - 1);
}
int main(){
    vector<int> arr = {5,3,2,4,1};
    int answer = CountInversion(arr);
    cout<<"Inversion : i < j and arr[i] > arr[j]"<<endl;
    cout<<"Number of Inversions in the array: "<<answer<<endl;
    return 0;
}