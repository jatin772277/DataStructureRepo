#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int secondLargest(vector<int>& arr){
    int largest = INT_MIN;
    int second_largest = INT_MIN;
    for(int i = 0;i < arr.size();i++){
        if(arr[i] > largest){
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] > second_largest && largest != arr[i]) second_largest = arr[i];
    }
    return second_largest;
}
int main(){
    vector<int> arr = {13,24,12,52,33,44,52};
    cout<<"The Second Largest in the Array: "<<secondLargest(arr)<<endl;
    return 0;
}