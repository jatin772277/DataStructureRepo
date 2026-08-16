#include <iostream>
using namespace std;

int main() {
    string str = "hello";
    int hash[26] = {0};

    for(int i = 0; i < str.size(); i++) {
        hash[str[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        if(hash[i] > 0) {
            cout << char(i + 'a') << " -> " << hash[i] << endl;
        }
    }

    return 0;
}