#include <bits/stdc++.h>
using namespace std;
// Using Segment Tree

struct SegmentTree{
    int n;
    vector<int>t;
    SegmentTree(vector<int>&a){
        n = a.size();
        t.resize(4*n);
        build(1,0,n-1,a);
    }
    void build(int node,int l,int r,vector<int>&a){
        if(l == r){
            t[node].push_back(a[l]);
            return;
        }
        int mid = l+(r-l)/2;
        build(2*node, l,mid, a);
        build(2*node + 1,mid+1,r,a);
        merge(tree[2*node].begin(), tree[2*node].end(),
            tree[2*node + 1].begin(), tree[2*node+1].end(),
        back_insert(tree[node]));
    }
    int query(int node,int l,int r,int ql,int qr,int val){
        if(r < ql || l > qr){
            return 0;
        }
        if(ql <= l && r <= qr){
            auto it = lower_bound(tree[node].begin(), tree[node].end(), val);
            return tree[node].end() - it;
        }
        int mid = (l+r)/2;
        return query(2*node, l,mid,ql,qr,val)+
                query(2*node +1, mid+1,r,ql,qr,val);
    }
    int query(int l,int r,int val){
        return query(1,0,n-1,l,r,val);
    }
    
};
int main(){
    int n;
    cin>>n;
    vector<int>A(n),B(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    SegmentTree st(A);
    for(int i=0;i<n;i++){
        int lo = i;
        int hi = n-1;
        int ans = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int cnt = st.query(i,mid,A[i]);
            if(cnt >= B[i]){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        if(ans == -1)cout<<-1<<'\n';
        else cout<<ans-i+1<<" ";
    }
    cout<<'\n';
    return 0;
}