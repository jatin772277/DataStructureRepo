#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {

        int left = 0;
        int count = 0;

        unordered_map<char, int> mpp;

        int n = s.size();

        for(int right = 0; right < n; right++) {

            mpp[s[right]]++;

            while(mpp.size() == 3) {

                count += n - right;

                mpp[s[left]]--;

                if(mpp[s[left]] == 0) {
                    mpp.erase(s[left]);
                }

                left++;
            }
        }

        return count;
    }
};

int main() {

    Solution obj;

    string s;
    cin >> s;

    cout << obj.numberOfSubstrings(s) << endl;

    return 0;
}