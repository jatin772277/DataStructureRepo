#include<iostream>
#include<vector>
using namespace std;
void printAllPrimeTilln(int n){
    //sieve of eratosthenes
    vector<bool> isPrime(n+1 ,true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2;i*i <= n;i++){
        if(isPrime[i]){
            for(int j = i*i;j <= n;j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(int i = 2;i <= n;i++){
        if(isPrime[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return;
}
int main(){
    int n;
    cout<<"Enter A Number: "<<endl;
    cin>>n;
    cout<<"All primes till "<<n<<" : "<<endl;
    printAllPrimeTilln(n);
    return 0;
}