#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:

    void dfs(string word, string beginWord,
             unordered_map<string,int> &mp,
             vector<string> &seq,
             vector<vector<string>> &ans){

        if(word == beginWord){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mp[word];

        for(int i = 0; i < word.size(); i++){
            char original = word[i];

            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;

                if(mp.count(word) && mp[word] + 1 == steps){
                    seq.push_back(word);
                    dfs(word, beginWord, mp, seq, ans);
                    seq.pop_back();
                }
            }

            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);

        unordered_map<string,int> mp;
        mp[beginWord] = 1;

        st.erase(beginWord);

        while(!q.empty()){

            string word = q.front();
            q.pop();

            int steps = mp[word];

            if(word == endWord)
                break;

            for(int i = 0; i < word.size(); i++){

                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++){

                    word[i] = ch;

                    if(st.count(word)){
                        st.erase(word);
                        q.push(word);
                        mp[word] = steps + 1;
                    }
                }

                word[i] = original;
            }
        }

        vector<vector<string>> ans;

        if(mp.find(endWord) != mp.end()){

            vector<string> seq;
            seq.push_back(endWord);

            dfs(endWord, beginWord, mp, seq, ans);
        }

        return ans;
    }
};

int main(){

    Solution obj;

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {
        "hot","dot","dog","lot","log","cog"
    };

    vector<vector<string>> ans = obj.findLadders(beginWord, endWord, wordList);

    for(auto path : ans){
        for(auto word : path)
            cout << word << " ";
        cout << endl;
    }

    return 0;
}