#include<iostream>
#include<vector>
using namespace std;
vector<int> BuySellStock(vector<int> &arr){
    vector<int> answer(3,-1);
    int minPrice = arr[0];
    int maxProfit = 0;
    for(int i = 0;i < arr.size();i++){
        minPrice = min(minPrice , arr[i]);
        maxProfit = max(maxProfit,arr[i] - minPrice);
    }
    answer[2] = maxProfit;
    for(int i = 0;i < arr.size();i++){
        if(arr[i] == minPrice) answer[0] = i + 1;
        if(arr[i] == (maxProfit + minPrice)) answer[1] = i+ 1;
    }
    return answer;
}
int main(){
    vector<int> arr = {7,1,5,3,6,4};
    vector<int> answer = BuySellStock(arr);
    cout<<"The max profit is "<<answer[2]<<" That Can be possible if  we buy stock on "<<
    answer[0]<<" th day and Sell this Stock on "<<answer[1]<<" th Day!!"<<endl;
    return 0;
}