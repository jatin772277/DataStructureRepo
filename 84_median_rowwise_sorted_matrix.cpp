#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int median(vector<vector<int>> &matrix, int R, int C) {
    int low = INT_MAX;
    int high = INT_MIN;
    for (int i = 0; i < R; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][C - 1]);
    }
    int req = (R * C) / 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cnt = 0;
        for (int i = 0; i < R; i++) {
            cnt += upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
        }
        if (cnt <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main() {
    vector<vector<int>> mat = {
        {1,5,7,9,11},
        {2,3,4,5,10},
        {9,10,12,14,16}
    };
    int answer = median(mat, 3, 5);
    cout<<"Median: "<<answer<<endl;
    return 0;
}