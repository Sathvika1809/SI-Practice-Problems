#include <bits/stdc++.h>
using namespace std;
#define INF 1e5
int main(){
    int n;
    cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    vector<int>B(n);
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    int C,D;
    cin>>C>>D;
    vector<int>dpA(n,INF);
    vector<int>dpB(n,INF);
    dpA[0]= A[0];
    dpB[0] = B[0];
    for(int i=1;i<n;i++){
        int ans1 = INF;
        int ans2 = INF;
        for(int j=max(0,i-C);j<i;j++){
            int sum = min(dpA[j],dpB[j]+D);
            ans1 = min(ans1,sum);
            int cur = min(dpB[j],dpA[j]+D);
            ans2 = min(ans2,cur);
            
        }
        dpA[i] = ans1+A[i];
        dpB[i] = ans2+B[i];
    }
    cout<<min(dpA[n-1],dpB[n-1])<<'\n';

    return 0;
}