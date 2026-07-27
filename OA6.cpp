#include <bits/stdc++.h>
using namespace std;

bool isSameReflection(string word1, string word2){
    if(word1.length() != word2.length()){
        return 0;
    }
    int len = word1.length();
    string word = word1+word2;
    int ok1 = 0;
    int ok2 = 0;
    for(int i=0;i<word.size();i++){
        if(word.substr(i,len)==word1){
            ok1 = 1;
        }
        if(word.substr(i,len)==word2){
            ok2 = 1;
        }
    }
    if(ok1 && ok2){
        return true;
    }else{
        return false;
    }
}
int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<isSameReflection(s1,s2)<<'\n';

    return 0;
}