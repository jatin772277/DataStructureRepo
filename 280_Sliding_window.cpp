#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//Type 1 Sliding Window
int MaxSumWindow(vector<int>& arr,int k){
    int maxSum = INT_MIN;
    int left = 0;
    int n = arr.size();
    int sum = 0;
    for(int right = 0;right < n;right++){
        sum += arr[right];
        if((right - left + 1) > k){
            sum -= arr[left];
            left++;
        }
        if((right - left + 1) == k) maxSum = max(maxSum,sum);
    }
    return maxSum;
}
//Type 2 Sliding Window
vector<int> MaxLengthSum(vector<int>& arr,int k){
    int left = 0;
    int sum = 0;
    int maxlen = INT_MIN;
    int bestLeft = -1;
    int bestRight = -1;
    int n = arr.size();
    for(int right = 0;right < n;right++){
        sum += arr[right];
        while(sum > k){
            sum -= arr[left];
            left++;
        }
        if(right- left + 1 > maxlen){
            maxlen = max(maxlen,right - left + 1);
            bestLeft = left;
            bestRight = right;
        }
    }
    vector<int> temp;
    for(int i = bestLeft;i <= bestRight;i++) temp.push_back(arr[i]);
    return temp;
}

int main(){
    vector<int> arr = {-1,2,3,-3,4,5,-1};
    int k = 4;
    int maxSumofWindow = MaxSumWindow(arr,k);
    cout<<"Constant Window maximum Sum: "<<maxSumofWindow<<endl;

    vector<int> arr2 = {2,5,1,7,10};
    k = 14;
    vector<int> result = MaxLengthSum(arr2,k);
    int largestSubarrayLengthwhoseSumislessthanequaltoK = result.size();
    cout<<"Max Length: "<<largestSubarrayLengthwhoseSumislessthanequaltoK<<endl;
    cout<<"Array of Max Size: ";
    for(int x : result) cout<<x<<" ";
    cout<<endl;


    return 0;
}