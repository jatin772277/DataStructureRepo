#include<iostream>
#include<vector>
using namespace std;
bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2;i * i <= n;i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main(){
    int n1 = 13,n2 = 17,n3 = 16,n4 = 40;
    bool ans1 = isPrime(n1);
    if(ans1) cout<<"It's Prime!!"<<endl;
    else cout<<"Not Prime!!"<<endl;

    ans1 = isPrime(n2);
    if(ans1) cout<<"It's Prime!!"<<endl;
    else cout<<"Not Prime!!"<<endl;

    ans1 = isPrime(n3);
    if(ans1) cout<<"It's Prime!!"<<endl;
    else cout<<"Not Prime!!"<<endl;

    ans1 = isPrime(n4);
    if(ans1) cout<<"It's Prime!!"<<endl;
    else cout<<"Not Prime!!"<<endl;
    return 0;
}