#include<bits/stdc++.h>

using namespace std;

int solve(string s,int n,int k){
    unordered_map<char,int>mpp;
    long long ans = 1e9;
    for(int i=0,j=0;i<n;i++){
       while(j<n && mpp.size() < k){
           mpp[s[j]]++;
           j++;
       }
       if(mpp.size() >= k){
        ans = min(ans,(long long)(j-i));
       }
       mpp[s[i]]--;
       if(mpp[s[i]] == 0){
           mpp.erase(s[i]);
       }
    }
    return ans;
}

int main(){
    string s ="";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        s.push_back(c);
    }
    unordered_map<char,int>mpp;
    for(auto it : s){
        mpp[it]++;
    }
    int k = (int)mpp.size();
    cout<<solve(s,n,k);
}