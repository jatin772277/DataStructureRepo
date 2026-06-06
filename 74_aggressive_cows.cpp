#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool possible(vector<int>& stalls, int cows, int minDist) {
    int countCows = 1;
    int lastPlaced = stalls[0];
    for(int i = 1; i < stalls.size(); i++) {
        if(stalls[i] - lastPlaced >= minDist) {
            countCows++;
            lastPlaced = stalls[i];
        }
        if(countCows >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls.back() - stalls.front();
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(possible(stalls, cows, mid)) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}
int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;
    int answer = aggressiveCows(stalls, cows);
    cout<<"Maximum Minimum Distance: "<<answer<<endl;
    return 0;
}