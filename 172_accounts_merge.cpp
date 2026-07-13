#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class DisjointSet{
    vector<int> rank,parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0;i <= n;i++) parent[i] = i;
    }
    int findUpar(int u){
        if(u == parent[u]) return u;
        return parent[u] = findUpar(parent[u]);
    }
    void UnionByRank(int u,int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
    int n = accounts.size();
    DisjointSet ds(n);
    unordered_map<string,int> mailNodeMap;
    for(int i = 0;i < n;i++){
        for(int j = 1;j < accounts[i].size();j++){
            string mail = accounts[i][j];
            if(mailNodeMap.find(mail) == mailNodeMap.end()) mailNodeMap[mail] = i;
            else ds.UnionByRank(i,mailNodeMap[mail]);
        }
    }
    vector<vector<string>> mergedMail(n);
    for(auto it : mailNodeMap){
        string mail = it.first;
        int node = ds.findUpar(it.second);
        mergedMail[node].push_back(mail);
    }
    vector<vector<string>> ans;
    for(int i = 0;i < n;i++){
        if(mergedMail[i].empty()) continue;
        sort(mergedMail[i].begin(),mergedMail[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto &mail : mergedMail[i]) temp.push_back(mail);
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    vector<vector<string>> accounts = {
    {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
    {"John", "johnsmith@mail.com", "john00@mail.com"},
    {"Mary", "mary@mail.com"},
    {"John", "johnnybravo@mail.com"}
    };
    vector<vector<string>> mergedAccounts = accountsMerge(accounts);
    for(int i = 0;i < mergedAccounts.size();i++){
        for(int j = 0;j < mergedAccounts[i].size();j++){
            cout<<mergedAccounts[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}