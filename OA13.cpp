#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>freq(1024,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        freq[a[i]]++;
    }
    for(int i=0;i<n;i++){
        int cur = a[i];
        int best = -1;
        for(int v=1;v<1024;v++){
            if(freq[v]==0)continue;
            if(v == cur && freq[v]<2)continue;
            int mask = cur | v;
            if(((mask+1) & mask)==0){
                // If mask+1 = 2^k
                best = v;
                break;
            }
        }
        cout<<best<<" ";
    }
    cout<<'\n';
    return 0;
}