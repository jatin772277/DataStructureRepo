#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool possible(vector<int> &arr,int threshold,int mid){
    long long sum = 0;
    for(int x : arr){
        sum += (x + mid - 1)/mid;
    }
    return sum <= threshold;
}
int smallestDivisorThreshold(vector<int> &arr , int threshold){
    int low = 1;
    int high = *max_element(arr.begin(),arr.end());
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(possible(arr,threshold,mid)) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
int main(){
    vector<int> arr = {1,2,5,9};
    int threshold = 6;
    int answer = smallestDivisorThreshold(arr,threshold);
    cout<<"Smallest Divisor that satisfy problem: "<<answer<<endl;
    return 0;
}