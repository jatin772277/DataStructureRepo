#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool possible(vector<int>& arr, int days, int capacity) {
    int requiredDays = 1;
    int currentLoad = 0;

    for(int weight : arr) {
        if(currentLoad + weight <= capacity) currentLoad += weight;
        else{
            requiredDays++;
            currentLoad = weight;
        }
    }
    return requiredDays <= days;
}
int shipWithinDays(vector<int>& arr, int days) {
    int low = *max_element(arr.begin(), arr.end());
    int high = 0;
    for(int weight : arr) {
        high += weight;
    }
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(possible(arr, days, mid)) high = mid - 1;
        else low = mid + 1;
    }

    return low;
}
int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    int answer = shipWithinDays(arr, days);
    cout << "Minimum Capacity Required: " << answer << endl;
    return 0;
}