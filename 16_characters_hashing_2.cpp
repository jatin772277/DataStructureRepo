#include <iostream>
using namespace std;

int main() {
    string str = "Hello123";
    int hash[128] = {0};

    for(int i = 0; i < str.size(); i++) {
        hash[str[i]]++;
    }

    for(int i = 0; i < 128; i++) {
        if(hash[i] > 0) {
            cout << char(i) << " -> " << hash[i] << endl;
        }
    }

    return 0;
}