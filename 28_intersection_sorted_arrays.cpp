#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b) {
    unordered_set<int> s1(a.begin(), a.end());
    unordered_set<int> result;
    for (int num : b) {
        if (s1.find(num) != s1.end()) {
            result.insert(num);
        }
    }
    return vector<int>(result.begin(), result.end());
}
int main() {
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 2, 4, 6};
    vector<int> ans = intersection(a, b);
    cout<<"Intersection: ";
    for(int x : ans){
        cout<<x<< " ";
    }
    return 0;
}