#include<iostream>
using namespace std;
void BacktrackPrint1toN(int n){
    if(n < 1) return;
    BacktrackPrint1toN(n-1);
    printf("%d ",n);
}
void BacktrackPrintNto1(int n){
    if(n < 1) return;
    cout<<n<<" ";
    BacktrackPrintNto1(n - 1);
}
int main(){
    int n;
    cout<<"Enter The Number: "<<endl;
    cin>>n;
    BacktrackPrint1toN(n);
    cout<<endl;
    BacktrackPrintNto1(n);
    return 0;
}