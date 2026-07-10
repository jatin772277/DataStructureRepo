// // There are n cities numbered from 0 to n-1. Given the array edges where 
// edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between 
// cities fromi and toi, and given the integer distanceThreshold.

// // Return the city with the smallest number of cities that are reachable
//  through some path and whose distance is at most distanceThreshold, If
//   there are multiple such cities, return the city with the greatest number.

// // Notice that the distance of a path connecting cities i and j is equal to the sum
//  of the edges' weights along that path.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int findTheCity(int n,vector<vector<int>>& edges,int distanceThreshold){
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    for(auto it : edges){
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }
    for(int i = 0;i < n;i++) dist[i][i] = 0;
    for(int via = 0;via < n;via++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(dist[i][via] == INT_MAX || dist[via][j] == INT_MAX) continue;
                dist[i][j] = min(dist[i][j],dist[i][via] + dist[via][j]);
            }
        }
    }
    int countcity = n;
    int cityno = -1;
    for(int city = 0;city < n;city++){
        int count = 0;
        for(int adjCity = 0;adjCity < n;adjCity++){
            if(dist[city][adjCity] <= distanceThreshold) count++;
        }
        if(count <= countcity){
            countcity = count;
            cityno = city;
        }
    }
    return cityno;
}
int main(){
    vector<vector<int>> edges;
    edges.push_back({0,1,2});
    edges.push_back({0,4,8});
    edges.push_back({1,4,2});
    edges.push_back({1,2,3});
    edges.push_back({2,3,1});
    edges.push_back({3,4,1});
    int n = 5;//Number of Nodes
    int distanceThreshold = 2;
    int city = findTheCity(n,edges,distanceThreshold);
    cout<<"City With Minimum Number of Neighbours At Threshold Distance: "<<city<<endl;
    return 0;
}