#include<iostream>
using namespace std;
int PowerExponentiation(int base,int power){
    if(power < 0) return -1;
    long long ans = 1;
    long long x = base;
    while(power > 0){
        if(power % 2 == 1){
            ans *= x;
            power--;
        }
        else{
            x *= x;
            power /= 2;
        }
    }
    return ans;
}
int main(){
    int x;
    int n;
    cout<<"Enter The Base: ";
    cin>>x;
    cout<<"Enter the Power: ";
    cin>>n;
    int ans = PowerExponentiation(x,n);
    cout<<"The Answer is: "<<ans<<endl;
    return 0;
}