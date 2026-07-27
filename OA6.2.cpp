#include <bits/stdc++.h>
using namespace std;
void divisors(int n,vector<int>&A){
    while(n){
        int rem = n%2;
        A.push_back(rem);
        n/=2;
    }
    return;
}
int main(){
   int P,Q;
   cin>>P>>Q;
   int x  = P^Q;
   cout<< __builtin_popcount(x)<<'\n';

    return 0;
}