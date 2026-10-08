#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int LongestRepeatingCharReplacement(string& str,int k){
    int left = 0;
    int maxlen = 0;
    int maxFreq = 0;
    int n = str.size();
    unordered_map<char,int> mpp;
    for(int right = 0;right < n;right++){
        mpp[str[right]]++;
        maxFreq = max(maxFreq,mpp[str[right]]);
        if((right - left + 1) - maxFreq > k){
            mpp[str[left]]--;
            left++;
        }
        maxlen = max(maxlen,right-left+1);
    }
    return maxlen;
}
int main(){
    string str = "AABABBA";
    int k = 2;
    int maxlen = LongestRepeatingCharReplacement(str,k);
    cout<<"Result: "<<maxlen<<endl;
    return 0;
}