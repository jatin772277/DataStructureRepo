#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> &arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(vector<int> &arr,int low,int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j =  low;j < high;j++){
        if(arr[j] < pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp  = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i+1);
}

void Quick_Sort(vector<int> &arr,int low ,int high){
    if(low < high){
        int q = partition(arr,low,high);
        Quick_Sort(arr,low,q-1);
        Quick_Sort(arr,q + 1,high);
    }
}

int main(){
    vector<int> arr = {23,34,43,12,11,17,41,25};
    printVector(arr);
    cout<<"Sorted Order: ";
    Quick_Sort(arr,0,arr.size() - 1);
    printVector(arr);
    return 0;
}