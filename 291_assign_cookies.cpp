#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int MaxSatisfiedChild(vector<int>& cookies,vector<int>& greed){
    sort(cookies.begin(),cookies.end());
    sort(greed.begin(),greed.end());
    int n = greed.size();
    int res = 0;
    for(int i = 0;i < cookies.size();i++){
        if(cookies[i] >= greed[res]) res++;
        else continue;
    }
    return res;
}
int main(){
    vector<int> cookies = {4,2,1,2,1,3};
    vector<int> greed = {1,5,3,3,4};
    int maxSatisfied = MaxSatisfiedChild(cookies,greed);
    cout<<"Maximum Children with their Greed Satisfied: "<<maxSatisfied<<endl;
    return 0;
}