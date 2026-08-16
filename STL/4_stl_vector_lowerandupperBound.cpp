#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 3, 3, 5, 7};
    vector<int> v1 = {3,4,5,6,7};
    auto it = lower_bound(v.begin(), v.end(), 3);
    auto it1 = upper_bound(v.begin(), v.end(), 5);
    cout << "Index1: " << it - v.begin() << endl;
    cout << "Value1: " << *it << endl;
    cout << "Index2: " << it1 - v.begin() << endl;
    cout << "Value2: " << *it1 << endl;
    swap(v,v1);
    cout<<"Vector v : ";
    for(int a : v) cout<<a<<" ";
    cout<<endl;
    cout<<"Vector v1: ";
    for(int a : v1) cout<<a<<" ";
    cout<<endl;
}