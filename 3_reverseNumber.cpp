#include<iostream>
#include<vector>
using namespace std;
int reverseNumber(int n){
    int reverse = 0;
    vector<int> vect;
    while(n > 0){
        int a = n % 10;
        n /= 10;
        vect.push_back(a);
    }
    int exp = 1;
    for(int i = vect.size() - 1; i >= 0; i--){
        reverse += exp * vect[i];
        exp *= 10;
    }
    return reverse;
}
int main(){
    int n;
    cout<<"Enter The Number: "<<endl;
    cin>>n;
    cout<<"Reversed Number: "<<reverseNumber(n)<<endl;
    return 0;
}