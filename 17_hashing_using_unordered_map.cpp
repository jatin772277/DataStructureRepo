#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string str = "Hello123!!";
    unordered_map<char, int> freq;

    for(char ch : str) {
        freq[ch]++;
    }

    for(auto it : freq) {
        cout << it.first << " -> " << it.second << endl;
    }

    return 0;
}