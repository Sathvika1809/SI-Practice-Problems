#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll merge(vector<ll>&V,int l,int m,int r,int lim){
    ll cnt = 0;
    int j = m+1;
    for(int i=l;i<=m;i++){
        while(j<=r && V[i]>V[j]+lim){
            j++;
        }
        cnt += (r-j+1);
    }
    vector<ll>temp;
    int i = l;
    j = m+1;
    while(i<=m && j<=r){
        if(V[i] <= V[j]){
            temp.push_back(V[i++]);
        }else{
            temp.push_back(V[j++]);
        }
    }
    while(i<=m){
        temp.push_back(V[i++]);
    }
    while(j<=r){
        temp.push_back(V[j++]);
    }
    for(int i=l;i<=r;i++){
        V[i] = temp[i-l];
    }
    return cnt;
}
ll solve(vector<ll>&V, int lo,int hi,ll lim){
    if(lo >= hi)return 0;
    int mid = lo+(hi-lo)/2;
    ll cnt = 0;
    cnt += solve(V,lo,mid,lim);
    cnt += solve(V,mid+1,hi,lim);
    cnt += merge(V,lo,mid,hi,lim);
}
int main(){
    int n,c,d;
    cin>>n>>c>>d;
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<ll>diff(n,0);
    for(int i=0;i<n;i++){
        diff[i] = a[i]-b[i];
    }
    int lim = d-c;
    cout<<solve(diff,0,n-1,lim)<<'\n';

    return 0;
}