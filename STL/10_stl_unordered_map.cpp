#include<bits/stdc++.h>
using namespace std;
void printMap(unordered_map<string,int> &mpp){
    for(auto it = mpp.begin();it!=mpp.end();it++) cout<<it->first<<":"<<it->second<<endl;
    cout<<endl;
}
int main(){
    unordered_map<string,int> mpp;
    mpp["abc"] = 23;
    mpp["syd"] = 24;
    mpp["brt"] = 25;
    mpp["jin"] = 236;
    mpp["hms"] = 237;
    printMap(mpp);
    mpp["hms"] = 234;
    mpp.emplace("hms",234);//can't change the value
    printMap(mpp);
    mpp.erase("hms");
    printMap(mpp);
    // mpp.erase(mpp.begin());
    // mpp.clear();
    // mpp.erase(mpp.begin(),mpp.begin()+2);
    // auto it = mpp.find("hms");//find occurances of key = "hms";
    // int a = mpp.empty();//checks the map is empty or not ;
    cout<<mpp.count("abc")<<endl;
    for(auto it : mpp) cout<<it.first<<" : "<<it.second<<endl;
    return 0;
}