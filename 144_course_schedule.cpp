#include<iostream>
#include<vector>
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

bool isCycleDetect(int numCourses, vector<vector<int>>& graph){
    vector<bool> visited(numCourses, false);
    vector<bool> pathVisited(numCourses, false);

    for(int i = 0; i < numCourses; i++){
        if(!visited[i]){
            if(dfsCheck(i, visited, pathVisited, graph))
                return true;
        }
    }

    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    vector<vector<int>> graph(numCourses);

    for(auto it : prerequisites){
        graph[it[1]].push_back(it[0]);
    }

    if(isCycleDetect(numCourses, graph))
        return false;
    else
        return true;
}

int main(){
    int numCourses = 2;

    vector<vector<int>> prerequisites = {
        {1,0},
        {0,1}
    };

    if(canFinish(numCourses, prerequisites))
        cout << "All Courses Can Be Finished!!!" << endl;
    else
        cout << "All Courses Can't Be Finished!!!" << endl;

    return 0;
}