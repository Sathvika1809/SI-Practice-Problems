#include <bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int>&costs,int m){
    unordered_map<int,int>freq;
    int n = costs.size();
    for(int i=0;i<n;i++){
        freq[costs[i]]++;
    }
    int maxm = *max_element(costs.begin(), costs.end());
    int minm = *min_element(costs.begin(),costs.end());
    
    while(m > 0){
        
        int mn = freq.begin()->first;
        int mx = freq.rbegin()->first;
        if(mn >= mx){
            return 0;
        }
        int leftCnt = freq.begin()->second;
        int rightCnt = freq.rbegin()->second;

        if(leftCnt <= rightCnt){
            if(leftCnt > m) break;
            freq[mn + 1] += leftCnt;
            m-= leftCnt;
            freq.erase(mn);
        }else{
            if(rightCnt > m){
                break;
            }
            freq[mx-1] += rightCnt;
            m-=rightCnt;
            freq.erase(mx);
        }
    }
    int mn = freq.begin()->first;
    int mx = freq.rbegin()->first;

    return mx-mn;
    
}