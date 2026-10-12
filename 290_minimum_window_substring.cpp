
#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
string MinWindow(string s, string t) {
    vector<int> mpp(256, 0);
    for(char ch : t) mpp[ch]++;
    int left = 0, count = 0, minLen = INT_MAX, start = 0;
    for(int right = 0; right < s.size(); right++) {
        if(mpp[s[right]] > 0) count++;
        mpp[s[right]]--;
        while(count == t.size()) {
            if(right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }
            mpp[s[left]]++;
            if(mpp[s[left]] > 0) count--;
            left++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}
int main() {
    string s = "ddaaabbca";
    string t = "abc";
    string ans = MinWindow(s, t);
    cout << "Minimum Window: " << ans << endl;
    cout << "Minimum Window Length: " << ans.size() << endl;
    return 0;
}
