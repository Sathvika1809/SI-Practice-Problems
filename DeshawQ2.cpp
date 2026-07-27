#include <bits/stdc++.h>
using namespace std;
void dfs(int u,vector<vector<int>>&adj,vector<int>&visited,vector<int>&colors,int& sz){
    visited[u] = 1;
    sz++;
    for(int v: adj[u]){
        if(!visited[v] && colors[u] == colors[v]){
            dfs(v,adj,vis,colors,sz);
        }
    }
}
long countRouteCycles(int tree_nodes,vector<int>tree_from,vector<int>tree_to,vector<int>colors){
    int n = tree_nodes;
    int m = tree_from.size();
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        adj[tree_from[i]].push_back(tree_to[i]);
        adj[tree_to[i]].push_back(tree_from[i]);
    }
    vector<int>visited(n+1,0);
    long ans = 0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            int sz = 0;
            dfs(i,adj,visited,colors,sz);
            if(sz >= 2){
                ans += ((sz-1)*(sz-2))/2;
            }
        }
    }
    return ans;
}


int main(){

}