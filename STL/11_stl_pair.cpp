#include<bits/stdc++.h>
using namespace std;

template<typename T1, typename T2>
void printPair(pair<T1,T2> &pr){
    cout << pr.first << " : " << pr.second << endl;
}

int main(){
    pair<int,int> pr = {1,4};
    printPair(pr);

    pair<string,int> pr2 = {"Jatin", 21};
    printPair(pr2);
    
    pair<pair<int,int> , int> pr3 = {{1,2},3};
    cout<<pr3.first.second<<endl;
    
    pair<pair<int,int> ,pair<int,int>> pr4;
    cout<<pr4.first.second<<"  :  "<<pr4.second.first<<endl;
    return 0;
}