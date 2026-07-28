#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll findSum(vector<int>&arr){
    ll ans = 0;
    int n = arr.size();
    for(int bit = 0;bit<32;bit++){
        ll cnt0 = 1;
        ll cnt1 = 0;
        int pref = 0;
        for(int i=0;i<n;i++){
            pref^=arr[i];

            if((pref >> bit)&1){
                ans += cnt0 *(1LL << bit);
                cnt1++;
            }else{
                ans += cnt1 *(1LL << bit);
                cnt0++;
            }
        }
    }
    return ans;
}





int main(){

}