#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
    vector<int> rank,parent,size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i = 0;i <= n;i++) parent[i] = i;
        }
        int findParent(int node){
            if(node == parent[node]) return node;
            return parent[node] = findParent(parent[node]);
        }
        void UnionByRank(int u,int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
            else if(rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        void UnionBySize(int u,int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if(size[ulp_u] == size[ulp_v]) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};
int main(){
    DisjointSet ds1(7);
    ds1.UnionByRank(1,2);
    ds1.UnionByRank(2,3);
    ds1.UnionByRank(4,5);
    ds1.UnionByRank(6,7);
    ds1.UnionByRank(5,6);
    cout<<"If 3 and 7 belongs to the same component??"<<endl;
    if(ds1.findParent(3) == ds1.findParent(7)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    ds1.UnionByRank(3,7);
    cout<<"After inserting Edge: "<<endl;
    cout<<"If 3 and 7 belongs to the same component??"<<endl;
    if(ds1.findParent(3) == ds1.findParent(7)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    DisjointSet ds2(7);
    ds2.UnionBySize(1,2);
    ds2.UnionBySize(2,3);
    ds2.UnionBySize(4,5);
    ds2.UnionBySize(6,7);
    ds2.UnionBySize(5,6);
    cout<<"If 3 and 7 belongs to the same component??"<<endl;
    if(ds2.findParent(3) == ds2.findParent(7)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    ds2.UnionByRank(3,7);
    cout<<"After inserting Edge: "<<endl;
    cout<<"If 3 and 7 belongs to the same component??"<<endl;
    if(ds2.findParent(3) == ds2.findParent(7)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}