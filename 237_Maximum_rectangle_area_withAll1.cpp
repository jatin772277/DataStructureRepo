#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> addArray(vector<int>& arr,vector<int>& brr){
    vector<int> temp;
    for(int i = 0;i < arr.size();i++) temp.push_back(arr[i] + brr[i]);
    return temp;
}
int largestRectangleArea(vector<int>& heights){
    stack<int> st;
    int maxA = 0;
    int n = heights.size();
    for(int i = 0;i <= n;i++){
        while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
            int height = heights[st.top()];
            st.pop();
            int width = 0;
            if(st.empty()) width = i;
            else width = i - st.top() - 1;
            maxA = max(maxA,width * height);
        }
        if(i < n) st.push(i);
    }
    return maxA;
}

int MaximumRectangleAreaOf1(vector<vector<int>>& rectangle){
    vector<int> temp = rectangle[0];
    int maxi = largestRectangleArea(temp);
    for(int i = 1;i < rectangle.size();i++){
        temp = addArray(temp,rectangle[i]);
        maxi = max(maxi,largestRectangleArea(temp));
    }
    return maxi;
}

int main(){
    vector<vector<int>> rectangle = {
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };
    int maxAreaof1 = MaximumRectangleAreaOf1(rectangle);
    cout<<"Max Area: "<<maxAreaof1<<endl;
    return 0;
}