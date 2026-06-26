#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n = 4;

    vector<vector<pair<int,int>>> adj(n + 1);

    adj[1].push_back({2,10});
    adj[1].push_back({3,5});

    adj[2].push_back({4,8});

    adj[3].push_back({2,3});
    adj[3].push_back({4,6});
    for(int i = 1; i <= n; i++) {

        cout << i << " -> ";

        for(auto edge : adj[i]) {
            cout << "(" << edge.first << "," << edge.second << ") ";
        }

        cout << endl;
    }
}