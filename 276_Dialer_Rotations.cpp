#include <bits/stdc++.h>
using namespace std;

int minRotationsToDial(string s) {
    int curr = 0;
    int total = 0;
    for (char ch : s) {
        int target = ch - '0';
        int cw = (target - curr + 10) % 10;
        int ccw = (curr - target + 10) % 10;
        total += min(cw, ccw);
        curr = target;
    }
    return total;
}

int main() {
    string s = "0192837465";
    cout << minRotationsToDial(s) << endl;   // 25
    return 0;
}