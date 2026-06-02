#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
void printIntervals(vector<pii>& intervals){
    for(int i = 0;i < intervals.size();i++){
        cout<<"{ "<<intervals[i].first<<","<<intervals[i].second<<" }  ";
    }
    cout<<endl;
}
bool cmp(pii &a,pii &b){
    return a.first < b.first;
}
vector<pii> MergeOverlappingInterval(vector<pii> &intervals){
    sort(intervals.begin(),intervals.end(),cmp);
    vector<pii> answer;
    for(int i = 0;i < intervals.size();i++){
        if(answer.empty() || intervals[i].first > answer.back().second){
            answer.push_back(intervals[i]);
        }
        else{
            answer.back().second = max(answer.back().second,intervals[i].second);
        }
    }
    return answer;
}
int main(){
    vector<pii> intervals = {{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}};
    vector<pii> answer = MergeOverlappingInterval(intervals);
    cout<<"The Overlapping Intervals are : ";
    printIntervals(answer);
    return 0;
}