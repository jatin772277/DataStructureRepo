#include<iostream>
using namespace std;
void printGCD(int n1,int n2){
    int gcd = 0;
    for(int i = 1;i <= min(n1,n2);i++){
        if((n1 % i == 0) && (n2 % i == 0)) gcd = i;
    }
    cout<<gcd<<endl;
}
int main(){
    int n1,n2;
    cout<<"Enter First Number: "<<endl;
    cin>>n1;
    cout<<"Enter Second Number: "<<endl;
    cin>>n2;
    cout<<"GCD / HCF of "<<n1<<" and "<<n2<<" : ";
    printGCD(n1,n2);
    return 0;
}