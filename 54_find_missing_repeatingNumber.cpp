#include <iostream>
#include <vector>
using namespace std;

vector<int> repeatingMissingNum(vector<int> &arr){
    long long n = arr.size();
    long long expectedSum = (n * (n + 1)) / 2;
    long long expectedSquaredSum = (n * (n + 1) * (2 * n + 1)) / 6;
    long long actualSum = 0;
    long long actualSquaredSum = 0;
    for(int x : arr){
        actualSum += x;
        actualSquaredSum += 1LL * x * x;
    }
    long long b = expectedSum - actualSum;
    long long a = expectedSquaredSum - actualSquaredSum;
    long long sum = a / b;
    long long missing = (sum + b) / 2;
    long long repeating = sum - missing;
    return {(int)repeating, (int)missing};
}
int main(){
    vector<int> arr = {4,3,6,2,1,1};
    vector<int> answer = repeatingMissingNum(arr);
    cout<<"Repeating Number: "<<answer[0]<<" And Missing Number: "<<answer[1]<<endl;
    return 0;
}