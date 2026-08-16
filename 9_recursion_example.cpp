#include<iostream>
using namespace std;
int printFactorial(int n){
    if(n == 0 || n == 1) return 1;
    return n * printFactorial(n-1);
}
void printName(int i,string Name){
    if(i == 0) return;
    cout<<"Name("<<i<<"): "<<Name<<endl;
    printName(i-1,Name);
}
void printTillN(int n){
    if(n == 0) return;
    printTillN(n-1);
    cout<<"Number till N: "<<n<<endl;
}
void printTill1(int n){
    if(n == 0) return;
    cout<<"Number till 1: "<<n<<endl;
    printTill1(n-1);
}
int main(){
    int n;
    cout<<"Enter The Number: "<<endl;
    cin>>n;
    int res = printFactorial(n);
    cout<<"Factorial: "<<res<<endl;
    printName(n,"Jatin");
    printTillN(n);
    printTill1(n);
    return 0;
}