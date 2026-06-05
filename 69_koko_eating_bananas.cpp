#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int find_max(vector<int> &arr){
    int max = INT_MIN;
    for(int x : arr){
        if(x > max) max = x;
    }
    return max;
}
long long totalHours(vector<int> &arr, int mid){
    long long hours = 0;
    for(int pile : arr){
        hours += (pile + mid - 1) / mid;
    }
    return hours;
}
int minEatingSpeed(vector<int> &arr,int h){
    int low =  1;
    int high = find_max(arr);
    while(low <= high){
        int mid = low + (high - low) / 2;
        long long hours = totalHours(arr,mid);
        if(hours <= h) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
int main(){
    vector<int> arr = {30,11,23,4,20};
    int h = 6;
    int answer = minEatingSpeed(arr,h);
    cout<<"Koko can Eat Minimum banana per hour to eat all bananas within "<<h<<" hours is: "
    <<answer<<endl;
    return 0;
}