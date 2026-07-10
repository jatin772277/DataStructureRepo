#include<iostream>
#include<vector>
#include<climits>
#include<iomanip>
using namespace std;
vector<vector<int>> FloyydWarshallAlgo(const vector<pair<int,pair<int,int>>>& edges,int n){
    vector<vector<int>> ans(n,vector<int>(n,INT_MAX));
    for(int i = 0;i < n;i++) ans[i][i] = 0;
    for(auto it : edges){
        int u = it.first;
        int v = it.second.first;
        int wt = it.second.second;
        ans[u][v] = wt;
    }
    for(int via = 0;via < n;via++){
        for(int i =0;i< n;i++){
            for(int j = 0;j < n;j++){
                if(ans[i][via] != INT_MAX && ans[via][j] != INT_MAX) 
                    ans[i][j] = min(ans[i][j], ans[i][via] + ans[via][j]);
            }
        }
    }
    for(int i = 0;i < n;i++){
        if(ans[i][i] < 0){
            cout<<"Negative Cycle Exists!!!"<<endl;
            break;
        }
    }
    return ans;
}
int main(){
    vector<pair<int,pair<int,int>>> edges;
    edges.push_back({0,{2,2}});
    edges.push_back({0,{1,6}});
    edges.push_back({0,{3,4}});
    edges.push_back({2,{4,1}});
    edges.push_back({2,{1,3}});
    edges.push_back({3,{1,1}});
    edges.push_back({4,{1,1}});
    int n = 5;//Number of Nodes
    vector<vector<int>> ans = FloyydWarshallAlgo(edges,n);
    cout << "\nDistance Matrix:\n\n";
    cout << setw(6) << " ";
    for(int j = 0; j < n; j++) cout << setw(6) << j;
    cout << '\n';
    for(int i = 0; i < n; i++){
        cout << setw(6) << i;
        for(int j = 0; j < n; j++){
            if(ans[i][j] == INT_MAX) cout << setw(6) << "INF";
            else cout << setw(6) << ans[i][j];
        }
        cout << '\n';
    }
}