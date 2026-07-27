#include <bits/stdc++.h>
using namespace std;
#define INF 1e5
typedef long long ll;
int check(int i,int j,int n){
    return (i>=0 && i<n && j>=0 && j<n);
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>grid(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    // In Djikstra the First Path U Find may not always be the best
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
    dist[0][0] = grid[0][0];
    pq.push({grid[0][0],0,0});
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    vector<vector<int>>dist(n,vector<int>(n,INF));
    int cost = 0;
    while(!pq.empty()){
        auto [cost,x,y] = pq.top();
        pq.pop();
        if(cost > dist[x][y]){
            continue;
        }
        if(x == n-1 && y == n-1){
            cout<<cost<<'\n';
            break;
        }
        
        for(int i=0;i<4;i++){
            int nx = x+ dx[i];
            int ny = y+ dy[i];
            if(check(nx,ny,n)){
                int newCost = max(cost,grid[nx][ny]);
                if(newCost < dist[nx][ny]){
                    dist[nx][ny] = newCost;
                    pq.push({newCost,nx,ny});
                }
            }
        }
    }

    return 0;
}