#include<iostream>
#include<vector>
#include<queue>
#include<climits>
# define Mod 100000
using namespace std;
int MinimumMultiplicationToEnd(int start,int end,vector<int> &arr){
    queue<pair<int,int>> q;
    //pair(steps,number);
    q.push({0,start});
    vector<int> dist(Mod,INT_MAX);
    dist[start] = 0;
    while(!q.empty()){
        int node = q.front().second;
        int steps = q.front().first;
        q.pop();
        for(auto it : arr){
            int num = (it * node) % Mod;
            if(steps + 1 < dist[num]){
                dist[num] = steps + 1;
                if(num == end) return steps + 1;
                q.push({steps + 1,num});
            }
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {2,5,7};
    int start = 3;
    int endd = 5250;
    int minStep = MinimumMultiplicationToEnd(start,endd,arr);
    cout<<"Minimum Steps To Reach End "<<endd<<" From Start "<<start<<" is: "<<minStep<<endl;
    return 0;
}