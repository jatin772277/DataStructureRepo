#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> &arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void Bubble_Sort(vector<int>& arr){
    for(int i = 0;i < arr.size()-1;i++){
        int didSwap = 0;
        for(int j = i + 1;j<arr.size();j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;
    }
}
int main(){
    vector<int> arr = {23,34,43,12,11,17,41,25};
    printVector(arr);
    cout<<"Sorted Order: ";
    Bubble_Sort(arr);
    printVector(arr);
    return 0;
}