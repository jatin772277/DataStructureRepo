#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> &arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void Insertion_Sort(vector<int>& arr){
    for(int i = 0;i < arr.size();i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }
}
int main(){
    vector<int> arr = {23,34,43,12,11,17,41,25};
    printVector(arr);
    cout<<"Sorted Order: ";
    Insertion_Sort(arr);
    printVector(arr);
    return 0;
}