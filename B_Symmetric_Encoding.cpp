#include<bits/stdc++.h>

using namespace std;

string solve(string s,int n){
    unordered_map<char,int>mpp;
    unordered_map<char,char>rel;
    string ans = "";
    for(auto it:s){
        mpp[it]++;
    }
    string r = "";
    for(auto it:mpp){
        r.push_back(it.first);
    }
    sort(r.begin(),r.end());
    int m = r.length();
    for(int i=0;i<m;i++){
        rel[r[i]] = r[m-i-1];
    }
    for(auto it:s){
        ans.push_back(rel[it]);
    }
    return ans;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<solve(s,n)<<endl;
    }
}