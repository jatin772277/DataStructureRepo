#include<iostream>
using namespace std;
long long power(long long base,int n,int m){
    long long ans = 1;
    for(int i = 0;i < n;i++){
        ans *= base;
        if(ans > m) return 2;//greater than m
    }
    if(ans == m) return 1;//equal
    return 0;//less
}
int NthRootBS(int n,int m){
    int low =1,high = m;
    while(low <= high){
        int mid = low + (high - low)/ 2;
        long long val = power(mid,n,m);
        if(val == 1) return mid;
        else if(val == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int main(){
    int m ,n;
    cout<<"Enter The Number: ";
    cin >> m;
    cout<<"Enter The root number: ";
    cin >> n;
    int answer = NthRootBS(n,m);
    cout<<n<<"th root of number "<<m<<" is: "<<answer<<endl;
    cout<<"-1 if doesn't exists!!"<<endl;
    return 0;
}