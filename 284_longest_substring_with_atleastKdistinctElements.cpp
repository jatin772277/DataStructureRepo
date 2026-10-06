#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int LongestSubstringWithKDistinct(string &str,int k){
    unordered_map<char,int> mpp;
    int left = 0;
    int maxlen = 0;
    int n = str.size();
    for(int right = 0;right < n;right++){
        mpp[str[right]]++;
        if(mpp.size() > k){
            mpp[str[left]]--;
            if(mpp[str[left]] == 0) mpp.erase(str[left]);
            left++;
        }
        if(mpp.size() <= k) maxlen = max(maxlen,right - left + 1);
    }
    return maxlen;
}
int main(){
    string str = "aaabbccbd";
    int k = 2;
    int maxlen = LongestSubstringWithKDistinct(str,k);
    cout<<"Result: "<<maxlen<<endl;
    return 0;
}