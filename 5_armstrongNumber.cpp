#include<iostream>
using namespace std;
bool isArmstrong(int n){
    int calNum = 0;
    int num = n;
    while(num > 0){
        int a = num % 10;
        calNum += a * a * a;
        num /= 10;
    }
    if(calNum == n) return true;
    else return false;
}
int main(){
    int n;
    cout<<"Enter a Number to check for Armstrong: "<<endl;
    cin>>n;
    if(isArmstrong(n)) cout<<"Number is Armstrong Number!!"<<endl;
    else cout<<"Not a Armstrong Number!!"<<endl;
    return 0;
}