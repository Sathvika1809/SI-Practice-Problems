#include <bits/stdc++.h>
using namespace std;

vector<int> findNearestIdx(vector<int>&arr,vector<int>&queries){
    int q = queries.size();
    vector<int>ans(q);
    int n = arr.size();
      vector<int>leftArr(n,-1);
      vector<int>rightArr(n,-1);
      stack<int>st;
      for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            leftArr[i] = st.top();
        }
        st.push(i);
      }
      st = stack<int>();
      for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            rightArr[i] = st.top();
        }
        st.push(i);
      }

    for(int i=0;i<q;i++){
        if(leftArr[i]==-1 && rightArr[i] == -1){
            ans[i] = -1;
        }else if(leftArr[queries[i]]==-1 && rightArr[queries[i]]!=-1){
            ans[i] = rightArr[queries[i]];
        }else if(rightArr[queries[i]]==-1 && leftArr[queries[i]]!=-1){
            ans[i] = leftArr[queries[i]];
        }
        else if(abs(queries[i]-leftArr[queries[i]])<= abs(queries[i]-rightArr[queries[i]])){
            ans[i] = leftArr[queries[i]];
        }else if(abs(queries[i]-leftArr[queries[i]]) > abs(queries[i]-rightArr[queries[i]])){
            ans[i] = rightArr[queries[i]];
        }
    }
    return ans;
}



int main(){



}