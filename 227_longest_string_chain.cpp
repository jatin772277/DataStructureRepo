#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
    static bool cmp(string& a,string& b){
        return a.size() < b.size();
    }
    bool checkPossible(string& s1,string& s2){
        if(s1.size() != s2.size() + 1) return false;
        int first = 0,second = 0;
        while(first < s1.size()){
            if(s1[first] == s2[second]){
                first++;
                second++;
            }
            else first++;
        }
        if(first == s1.size() && second == s2.size()) return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n = words.size();
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i = 0;i < n;i++){
            for(int prev = 0;prev < i;prev++){
                if(checkPossible(words[i],words[prev]) && dp[i] < dp[prev] + 1){
                    dp[i] = dp[prev] + 1;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
            }
        }
        return maxi;
    }
};
int main() {
    vector<string> words = {"a", "ab", "abc", "abd", "abce", "abcf", "abdef"};
    Solution obj;
    int result = obj.longestStrChain(words);
    cout<<"Length of Longest String Chain: "<<result<<endl;
    return 0;
}