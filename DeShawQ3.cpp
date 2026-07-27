#include <bits/stdc++.h>
using namespace std;

bool findWays(int l,int r,string s,vector<vector<int>>&dp){
    if(l>r){
        return true;
    }
    if(dp[l][r] != -1)return dp[l][r];
    if(s[l] == s[r] && findWays(l+1,r-1,s,dp)){
        return dp[l][r] = 1;
    }
    for(int k=l;k<r;k++){
        if(findWays(l,k,s,dp) && findWays(k+1,r,s,dp)){
            return dp[l][r] = 1;
        }
    }
    return dp[l][r] = 0;
    
}
vector<int>findValidPasswords(vector<string>passwords){
    int n = passwords.size();
    vector<vector<int>>dp;
    vector<int>ans;
    string s;
    for(string str: passwords){
        s = str;
        int n = s.size();
        dp.assign(n,vector<int>(n,-1));
        ans.push_back(findWays(0,n-1,s,dp));
    }
    return ans;
}



int main(){


    return 0;
}