#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

vector<int> concatenateAndMultiply(string &s, vector<vector<int>> &queries) {
    int n = s.size();

    vector<int> position;
    vector<long long> digits;

    for (int i = 0; i < n; i++) {
        if (s[i] != '0') {
            position.push_back(i);
            digits.push_back(s[i] - '0');
        }
    }

    int m = position.size();

    vector<long long> power10(m + 1, 1);
    vector<long long> prefixNumber(m + 1, 0);
    vector<long long> prefixSum(m + 1, 0);

    for (int i = 1; i <= m; i++)
        power10[i] = (power10[i - 1] * 10) % MOD;

    for (int i = 0; i < m; i++) {
        prefixNumber[i + 1] = (prefixNumber[i] * 10 + digits[i]) % MOD;
        prefixSum[i + 1] = prefixSum[i] + digits[i];
    }

    vector<int> answer;

    for (auto query : queries) {
        int l = query[0];
        int r = query[1];

        int left = lower_bound(position.begin(), position.end(), l) - position.begin();
        int right = upper_bound(position.begin(), position.end(), r) - position.begin();

        if (left == right) {
            answer.push_back(0);
            continue;
        }

        int len = right - left;

        long long number =
            (prefixNumber[right] -
             (prefixNumber[left] * power10[len]) % MOD +
             MOD) % MOD;

        long long sum = prefixSum[right] - prefixSum[left];

        answer.push_back((number * (sum % MOD)) % MOD);
    }

    return answer;
}

int main() {
    string s = "10203004";

    vector<vector<int>> queries = {
        {0, 7},
        {1, 3},
        {4, 6}
    };

    vector<int> ans = concatenateAndMultiply(s, queries);

    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
