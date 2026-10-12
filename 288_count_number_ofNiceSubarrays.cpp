#include <iostream>
#include <vector>
using namespace std;

int AtMostK(vector<int>& arr, int k) {
    int left = 0, count = 0, odd = 0;

    for(int right = 0; right < arr.size(); right++) {
        odd += arr[right] % 2;

        while(odd > k) {
            odd -= arr[left] % 2;
            left++;
        }

        count += right - left + 1;
    }

    return count;
}

int CountNiceSubarrays(vector<int>& arr, int k) {
    return AtMostK(arr, k) - AtMostK(arr, k - 1);
}

int main() {
    vector<int> arr = {1, 1, 2, 1, 3, 4, 5, 7};
    int k = 3;
    cout << "Nice Subarrays Count: " << CountNiceSubarrays(arr, k) << endl;
    return 0;
}