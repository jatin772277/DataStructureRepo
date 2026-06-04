#include <iostream>
#include <vector>
using namespace std;

int findKRotation(vector<int>& arr){
    int low = 0, high = arr.size() - 1;

    while(low < high){
        int mid = low + (high - low) / 2;

        if(arr[mid] > arr[high]){
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }

    return low;
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};

    cout << "No of Rotation in Array: "
         << findKRotation(arr) << endl;

    return 0;
}