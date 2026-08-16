#include<iostream>
using namespace std;
void SumParameterizedRecursion(int i,int sum){
    if(i < 1){
        cout<<sum<<" is The total Sum!!"<<endl;
        return;
    }
    return SumParameterizedRecursion(i - 1,sum + i);
}
int functionalRecursion(int n){
    if(n == 0) return 0;
    return n + functionalRecursion(n - 1);
}
int main(){
    int n;
    cout<<"Enter The Number: "<<endl;
    cin>>n;
    SumParameterizedRecursion(n,0);
    int sum = functionalRecursion(n);
    printf("Computed Sum via Functional way: %d\n",sum);
    return 0;
}