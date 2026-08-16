#include<iostream>
using namespace std;
void printAllDivision(int n){
    for(int i = 1;i <= n/2;i++){
        if(n % i == 0) cout<<i<<" ";
    }
    cout<<n<<" !!!"<<endl;
    return;
}
int main(){
    int n;
    cout<<"Enter A Number: "<<endl;
    cin>>n;
    cout<<"All Divisions of "<<n<<" : "<<endl;
    printAllDivision(n);
    return 0;
}