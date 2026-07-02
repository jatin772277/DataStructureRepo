#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool dfs(int node,int val,int color[],vector<vector<int>> &graph){
    color[node] = val;
    for(auto it : graph[node]){
        if(color[it] == -1){
            if(dfs(it,!val,color,graph)) return false;
        }
        else if(color[it] == val) return false;
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int color[graph.size()];
    for(int i = 0;i < graph.size();i++) color[i] = -1;
    for(int i = 0;i < graph.size();i++){
        if(color[i] == -1){
            if(dfs(i,0,color,graph)) return false;
        }
    }
    return true;
}
vector<vector<int>> matrixToList(vector<vector<int>>& matrix) {
    int V = matrix.size();
    vector<vector<int>> adj(V);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }

    return adj;
}
int main(){
    vector<vector<int>> graph1 = {
        {0,1,0,0,0,0,0,0,0,0},
        {1,0,1,0,0,0,0,0,0,0},
        {0,1,0,1,0,1,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0},
        {0,0,0,1,0,0,0,1,0,0},
        {0,0,1,0,0,0,1,0,0,0},
        {0,0,0,0,0,1,0,1,0,0},
        {0,0,0,0,1,0,1,0,1,0},
        {0,0,0,0,0,0,0,1,0,1},
        {0,0,0,0,0,0,0,0,1,0}
    };
    vector<vector<int>> graph2 = {
        {0,1,0,0,0,0,0,0},
        {1,0,1,0,0,1,0,0},
        {0,1,0,1,0,0,0,0},
        {0,0,1,0,1,0,1,0},
        {0,0,0,1,0,1,0,0},
        {0,1,0,0,1,0,0,0},
        {0,0,0,1,0,0,0,1},
        {0,0,0,0,0,0,1,0}
    };
    graph1 = matrixToList(graph1);
    graph2 = matrixToList(graph2);
    bool ans1 = isBipartite(graph1);
    bool ans2 = isBipartite(graph2);
    cout<<"(no Adjacent node should have same colour and number of colour is 2): Bipartite Graph."<<endl;
    if(ans1) cout<<"Graph is Bipartite Graph!!!"<<endl;
    else cout<<"Not a Bipartite Graph!!!"<<endl;
    if(ans2) cout<<"Graph is Bipartite Graph!!!"<<endl;
    else cout<<"Not a Bipartite Graph!!!"<<endl;
    return 0;
}