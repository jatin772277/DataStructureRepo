#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> PrimeFactorisation(const vector<int>& queries){
    int largest = 0;
    for(int x : queries) if(x > largest) largest = x;
    if(largest < 2) return {};
    vector<int> SPF(largest + 1);
    for(int i = 0;i <= largest;i++) SPF[i] = i;
    SPF[0] = 0;
    SPF[1] = 1;

    for(int i = 2;i * i <= largest;i++){
        if(SPF[i] == i){
            for (int j = i * i; j <= largest; j += i) {
                if (SPF[j] == j) SPF[j] = i;
            }
        }
    }

    vector<vector<int>> result;
    for(int x : queries){
        vector<int> factors;
        while(x > 1){
            factors.push_back(SPF[x]);
            x /= SPF[x];
        }
        result.push_back(factors);
    }
    return result;
}
int main(){
    int Q;
    cout<<"Enter Number of Queries: "<<endl;
    cin>>Q;
    vector<int> queries;
    for(int i = 0; i < Q; i++){
        int x;
        cout << "Enter Number: ";
        cin >> x;
        queries.push_back(x);
        cout << endl;
    }
    vector<vector<int>> PrimeFactors = PrimeFactorisation(queries);
    cout<<"Prime Factorisation: "<<endl;
    for(int i = 0; i < Q; i++){
        cout << queries[i] << " = ";
        for(int j = 0; j < PrimeFactors[i].size(); j++){
            cout<<PrimeFactors[i][j];
            if(j + 1 < PrimeFactors[i].size()) cout << " x ";
        }
        cout<<endl;
    }
    return 0;
}