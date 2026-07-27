#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class DSU{
    int n;
    vector<int>parent,size;
    DSU(int N){
        n = N;
        size.assign(N+1,1);
        parent.resize(N+1);
        for(int i=1;i<=N;i++){
            parent[i] = i;
        }
    }
    int find(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void unions(int u,int v){
        int ul_u = find(u);
        int ul_v = find(v);
        if(ul_u != ul_v){
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        }
    }
};

void solve(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<N-1;++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>A(n+1);
    map<int,vector<int>>vals;
    for(int i=1;i<=n;i++){
        cin>>A[i];
        vals[A[i]].push_back(i);
    }
    DSU dsu(n);
    vector<bool>temp(n+1, false);
    ll tot = 0;

    for(auto const& [val,nodes] : vals){
        for(int u:nodes){
            temp[u] = true;
        }
        for(int u: nodes){
            for(int v: adj[u]){
                if(temp[v]){
                    dsu.unions(u,v);
                }
            }
        }
        vector<int>vis;
        for(int u:nodes){
            // Cnt Special Paths with diff root
            vis.push_back(dsu.find(u));
        }
        sort(vis.begin(), vis.end());
        vis.erase(unique(vis.begin(),vis.end()),vis.end());
        for(int root : vis){
            ll k = dsu.size[root];
            tot += (k*(k-1))/2;
        }
    }
    cout<<tot<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr)
}