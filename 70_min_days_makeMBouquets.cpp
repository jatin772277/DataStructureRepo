#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;
        for (int bloom : bloomDay) {
            if(bloom <= day){
                flowers++;
                if(flowers == k){
                    bouquets++;
                    flowers = 0;
                }
            } 
            else flowers = 0;
        }
    return bouquets >= m;
}
int minDays(vector<int>& bloomDay, int m, int k) {
        long long required = 1LL * m * k;
        if (required > bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (canMake(bloomDay, m, k, mid)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
}
int main(){
    vector<int> arr = {7,7,7,7,13,11,12,7};
    int m = 2;
    int k = 3;
    int answer = minDays(arr,m,k);
    cout<<"Minimum days to make "<<m<<" bouquets is: "<<answer<<endl;
    return 0;
}