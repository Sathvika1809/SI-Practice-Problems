#include <bits/stdc++.h>
using namespace std;

bool check(unordered_map<char,int> &freq){
    return freq.size()==5 &&
           freq['a']==1 &&
           freq['e']==1 &&
           freq['i']==1 &&
           freq['o']==1 &&
           freq['u']==1;
}


int vowelstring(string s){
    int n = s.size();
    if(n<5){
        return 0;
    }
    int cnt = 0;
    unordered_map<char,int>freq;
    for(int i=0;i<5;i++){
        if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'){
            break;
        }
        freq[s[i]]++;
    }
    if(check(freq)){
        cnt++;
    }
    for(int i=5;i<n;i++){
        freq[s[i-5]]--;
        if(freq[s[i-5]]==0){
            freq.erase(s[i-5]);
        }
        freq[s[i]]++;
        if(check(freq)){
            cnt++;
        }
    }
    return cnt;
    
}







int main(){


}