#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int SJF(vector<int>& at, vector<int>& bt) {
    int n = at.size();
    vector<pair<int, int>> processes;
    for (int i = 0; i < n; i++) processes.push_back({at[i],bt[i]});
    sort(processes.begin(), processes.end());
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    int currentTime = 0;
    int i = 0;
    int totalTime = 0;

    while (i < n || !pq.empty()) {
        while (i < n && processes[i].first <= currentTime) {
            pq.push({processes[i].second, processes[i].first});
            i++;
        }

        if (pq.empty()) {
            currentTime = processes[i].first;
            continue;
        }

        auto process = pq.top();
        pq.pop();
        int burstTime = process.first;
        currentTime += burstTime;
        totalTime = currentTime;
    }
    return totalTime;
}

int main() {
    vector<int> bt = {4,3,7,1,2};
    vector<int> at = {1,2,3,7,9};
    int totalTime = SJF(at,bt);
    cout<<"Total Time for completion of all processes: "<<totalTime<<endl;
    return 0;
}
