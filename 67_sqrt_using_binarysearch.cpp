#include<iostream>
using namespace std;
int sqrtBS(int n){
    int low = 1,high = n;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int val = mid * mid;
        if(val <= n) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}
int main(){
    int n;
    cout<<"Enter that N you want the square root of : ";
    cin>>n;
    int answer = sqrtBS(n);
    cout<<endl<<"Floor value of square root of "<<n<<" is: "<<answer<<endl;
    return 0;
}