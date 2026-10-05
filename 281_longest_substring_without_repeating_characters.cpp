#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int lengthOfLongestSubstring(string s){
    unordered_map<char,int> mpp;
    int left = 0,maxlen = 0,n = s.size();

    for(int right = 0;right < n;right++){
        if(mpp.find(s[right]) != mpp.end()) left=max(left,mpp[s[right]]+1);
        mpp[s[right]] = right;
        maxlen = max(maxlen,right - left + 1);
        cout<<"Window: "<<s.substr(left,right-left+1)
            <<"  Length: "<<right-left+1<<endl;
    }
    return maxlen;
}
int main(){
    string s="cadbzabcd";
    int result=lengthOfLongestSubstring(s);

    cout<<"\nLongest Substring Length: "<<result<<endl;

    return 0;
}