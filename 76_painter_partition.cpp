#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool possible(vector<int> &boards, int painters, int maxLength) {
    int painter = 1;
    long long length = 0;
    for(int i = 0; i < boards.size(); i++) {
        if(length + boards[i] <= maxLength) length += boards[i];
        else {
            painter++;
            length = boards[i];
            if(painter > painters) return false;
        }
    }
    return true;
}

int MinTimeToPaintBoards(vector<int> &boards, int painters) {
    int n = boards.size();
    if(painters > n) return -1;
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(possible(boards, painters, mid)){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

int main() {
    vector<int> boards = {10, 20, 30, 40};
    int painters = 2;
    int answer = MinTimeToPaintBoards(boards, painters);
    cout<<"Minimum time required: "<<answer<<endl;
    return 0;
}