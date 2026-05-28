#include<iostream>
#include<vector>
using namespace std;
int Kadane_algo(vector<int> &arr){
    int maximum = arr[0];
    int sum = 0;
    for(int i = 0;i < arr.size();i++){
        sum += arr[i];
        maximum = max(maximum,sum);
        if(sum < 0) sum = 0;
    }
    return maximum;
}
int main(){
    vector<int> arr = {2, -1, 3, 4, -2, 1, -5, 4};
    int maxSum = Kadane_algo(arr);
    cout<<"The Maximum Subarray Sum in the array is: "<<maxSum<<endl;
    return 0;
}