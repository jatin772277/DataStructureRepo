#include <iostream>
#include <vector>
#include <queue>
using namespace std;

double minimiseMaxDistance(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<double,int>> pq;
    for(int i = 0; i < n - 1; i++) pq.push({arr[i + 1] - arr[i], i});

    for(int gasStation = 1; gasStation <= k; gasStation++) {
        auto top = pq.top();
        pq.pop();
        int idx = top.second;
        howMany[idx]++;
        double initialDiff = arr[idx + 1] - arr[idx];
        double newSectionLength = initialDiff / (howMany[idx] + 1);

        pq.push({newSectionLength, idx});
    }
    return pq.top().first;
}
int main() {
    vector<int> arr = {1, 13, 17, 23};
    int k = 5;
    cout<<"Minimized maximum distance: "<<minimiseMaxDistance(arr, k)<<endl;
}