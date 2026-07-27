#include <bits/stdc++.h>
using namespace std;
int CountStrings(int idx,string& s,int n,string curr,vector<int>&dp){
    if(idx >= n){
        return 1;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    int nottake = CountStrings(idx+1,s,n,curr,dp);
    int take = 0;
    if(s[idx]!=s[idx+1]){
        take = 1+CountStrings(idx+2,s,n,curr+s[idx],dp);
    }
    return dp[idx] = take + nottake;
}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    string curr = "";
    cout<<CountStrings(0,s,n,curr,dp);
}