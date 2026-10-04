#include<iostream>
#include<vector>
using namespace std;
void PrintPrimes(int n){
    if(n < 2) return;
    vector<int> Primes(n+1,1);
    Primes[0] = Primes[1] = 0;
    for(int i = 2;i*i <= n;i++){
        if(Primes[i] == 1){
            for(int j = i*i;j <= n;j += i){
                Primes[j] = 0;
            }
        }
    }
    for(int i = 0;i <= n;i++) if(Primes[i] == 1) cout<<i<<" ";
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter limit Number of Prime Printing: ";
    cin>>n;
    cout<<endl;
    cout<<"Primes till "<<n<<"!!!!!!"<<endl;
    PrintPrimes(n);
    return 0;
}