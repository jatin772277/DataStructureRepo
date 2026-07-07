#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto it : flights) graph[it[0]].push_back({it[1],it[2]});
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        //{stops,{node,dist}}
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        while(!q.empty()){
            auto it = q.front();q.pop();
            int stops = it.first;
            int node = it.second.first;
            int distance = it.second.second;
            if(stops > k) continue;
            for(auto iter : graph[node]){
                int v = iter.first;
                int edgeWt = iter.second;
                if(distance + edgeWt < dist[v] && stops <= k){
                    dist[v] = distance + edgeWt;
                    q.push({stops+1,{v,distance + edgeWt}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
}
int main(){
    vector<vector<int>> flights;
    flights.push_back({0,1,5});
    flights.push_back({0,3,2});
    flights.push_back({3,1,2});
    flights.push_back({1,2,5});
    flights.push_back({1,4,1});
    flights.push_back({4,2,1});
    //5 is Number of Total Stops
    int src = 0;
    int dst = 2;
    int k = 2;
    int cheapestPrice = findCheapestPrice(5,flights,src,dst,k);
    cout<<"Cheapest Price of Reaching Destination "<<dst<<" From Source "<<src;
    cout<<" Within "<<k<<" Stops is: "<<cheapestPrice<<endl;
    return 0;
}