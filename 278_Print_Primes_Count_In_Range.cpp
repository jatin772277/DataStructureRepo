#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> CountPrimesInRange(const vector<pair<int,int>> &queries){
    int largest = INT_MIN;
    for(auto &q : queries) if(q.second > largest) largest = q.second;

    if(largest < 2) return {};
    vector<int> Primes(largest+1,1);
    Primes[0] = Primes[1] = 0;

    for(int i = 2;i * i <= largest;i++){
        if(Primes[i] == 1){
            for(int j = i*i;j <= largest;j += i){
                Primes[j] = 0;
            }
        }
    }

    vector<int> PrefixCount(largest+1,0);
    PrefixCount[0] = Primes[0];
    for(int i = 1;i <= largest;i++) PrefixCount[i] = PrefixCount[i-1] + Primes[i];
    
    vector<int> result;
    for(auto &q : queries){
        int L = q.first;
        int R = q.second;
        result.push_back(PrefixCount[R]
             - (L > 0 ? PrefixCount[L - 1] : 0));
    }
    return result;
}
int main(){
    int Q;
    cout<<"Enter Number of Queries: "<<endl;
    cin>>Q;
    vector<pair<int,int>> queries;
    for(int i = 0;i < Q;i++){
        cout<<"Enter First Queries L and R: ";
        int x,y;
        cin>>x>>y;
        queries.push_back({x,y});
        cout<<endl;
    }
    vector<int> CountPrimes = CountPrimesInRange(queries);
    for(int c : CountPrimes) cout<<c<<" ";
    cout<<endl;
    return 0;
}