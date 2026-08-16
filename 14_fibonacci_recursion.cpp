#include<iostream>
using namespace std;
int NthFibonacci(int n,int first,int second){
    if(n == 1) return first;
    if(n == 2) return second;
    return NthFibonacci(n - 1,second,second + first);
}
int NthFibonacci2(int n){
    if(n <= 2) return 1;
    return NthFibonacci2(n-1) + NthFibonacci2(n-2);
}

int main(){
    int n;
    cout<<"Enter N: "<<endl;
    cin>>n;
    cout<<"Nth term for the Fibonacci Series: "<<NthFibonacci(n,1,1)<<endl;
    cout<<"Nth term for the Fibonacci Series: "<<NthFibonacci2(n)<<endl;
    return 0;
}