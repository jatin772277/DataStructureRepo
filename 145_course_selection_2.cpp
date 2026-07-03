#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool dfsCheck(int source, vector<bool>& visited,
              vector<bool>& pathVisited,
              vector<vector<int>>& graph){
    visited[source] = true;
    pathVisited[source] = true;

    for(auto it : graph[source]){
        if(!visited[it]){
            if(dfsCheck(it, visited, pathVisited, graph))
                return true;
        }
        else if(pathVisited[it])
            return true;
    }

    pathVisited[source] = false;
    return false;
}

bool isCycleDetect(int n, vector<vector<int>>& graph){
    vector<bool> visited(n, false);
    vector<bool> pathVisited(n, false);

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            if(dfsCheck(i, visited, pathVisited, graph))
                return true;
        }
    }

    return false;
}

void dfs(int source, vector<bool>& visited,
         stack<int>& st,
         vector<vector<int>>& graph){

    visited[source] = true;

    for(auto it : graph[source]){
        if(!visited[it])
            dfs(it, visited, st, graph);
    }

    st.push(source);
}

vector<int> topologicalOrdering(int n, vector<vector<int>>& graph){
    vector<bool> visited(n, false);
    stack<int> st;

    for(int i = 0; i < n; i++){
        if(!visited[i])
            dfs(i, visited, st, graph);
    }

    vector<int> topo;

    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
    vector<vector<int>> graph(numCourses);

    for(auto it : prerequisites)
        graph[it[1]].push_back(it[0]);

    if(isCycleDetect(numCourses, graph))
        return {};

    return topologicalOrdering(numCourses, graph);
}

int main(){

    int numCourses = 4;

    vector<vector<int>> prerequisites = {
        {1,0},
        {2,0},
        {3,1},
        {3,2}
    };

    vector<int> ans = findOrder(numCourses, prerequisites);

    if(ans.empty()){
        cout << "Course Schedule is Not Possible!!!" << endl;
    }
    else{
        cout << "One Possible Order is: ";

        for(int x : ans)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}