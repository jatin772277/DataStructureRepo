#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

int ladderLength(string beginWord,string endWord,vector<string>& wordList){
    queue<pair<string,int>> q;
    unordered_set<string> st;
    for(auto it : wordList){
        st.insert(it);
    }
    if(st.find(endWord) == st.end()) return 0;
    q.push({beginWord,1});
    st.erase(beginWord);
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word == endWord) return steps;
        for(int i = 0;i < word.size();i++){
            char original = word[i];
            for(char ch = 'a';ch <= 'z';ch++){
                word[i] = ch;
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word,steps + 1});
                }
            }
            word[i] = original;
        }
    }
   return 0;
}
int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList;
    wordList.push_back("hot");
    wordList.push_back("dot");
    wordList.push_back("dog");
    wordList.push_back("lot");
    wordList.push_back("log");
    wordList.push_back("cog");
    int ans = ladderLength(beginWord,endWord,wordList);
    cout<<"Length of Shortest Transformation Sequence: "<<ans<<endl;
    return 0;
}