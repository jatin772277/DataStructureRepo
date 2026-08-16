#include<bits/stdc++.h>
using namespace std;

void printMap(multimap<string,int> &mpp){
    for(auto it = mpp.begin(); it != mpp.end(); it++)
        cout << it->first << " : " << it->second << endl;
    cout << endl;
}

int main(){

    multimap<string,int> mpp;

    mpp.insert({"abc",23});
    mpp.insert({"syd",24});
    mpp.insert({"brt",25});
    mpp.insert({"jin",236});
    mpp.insert({"hms",237});

    printMap(mpp);

    // duplicate keys allowed
    mpp.insert({"hms",234});
    mpp.emplace("hms",240);

    printMap(mpp);

    mpp.erase("hms");   // removes all entries with key "hms"

    printMap(mpp);

    cout << mpp.count("abc") << endl;

    for(auto it : mpp)
        cout << it.first << " : " << it.second << endl;

    return 0;
}