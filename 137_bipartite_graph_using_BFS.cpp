#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool check(int start,int V,vector<vector<int>> &graph,int color[]){
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            int node = q.front();q.pop();
            for(auto it : graph[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]) return false;
            }
        }
        return true;
}
bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int color[V];
        for(int i = 0;i < V;i++) color[i] = -1;
        for(int i = 0;i < V;i++){
            if(color[i] == -1){
                if(!check(i,V,graph,color)) return false;
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