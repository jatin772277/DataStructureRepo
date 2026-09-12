#include <iostream>
#include <vector>
using namespace std;
vector<int> primeFactors(int n) {
    vector<int> ans;
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ans.push_back(i);
            n = n / i;
        }
    }
    if(n > 1) ans.push_back(n);
    return ans;
}
void print(vector<int> arr) {
    for(int x : arr) cout << x << " ";
    cout << endl;
}
int main() {
    int n1 = 60;
    int n2 = 108;
    int n3 = 49;
    int n4 = 27;
    vector<int> ans1 = primeFactors(n1);
    vector<int> ans2 = primeFactors(n2);
    vector<int> ans3 = primeFactors(n3);
    vector<int> ans4 = primeFactors(n4);
    cout<<"Prime factors of "<<n1<<": ";
    print(ans1);
    cout<<"Prime factors of "<<n2<<": ";
    print(ans2);
    cout<<"Prime factors of "<<n3<<": ";
    print(ans3);
    cout<<"Prime factors of "<<n4<<": ";
    print(ans4);
    return 0;
}