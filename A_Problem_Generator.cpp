#include<bits/stdc++.h>

using namespace std;

int solve(int m,int n,string s){
    unordered_map<char,int>mpp;
    long long val = m * 7;
    for(char it:s){
        mpp[it]++;
    }
    long long sum = 0;
    for(auto it : mpp){
        if(it.second > m){
            sum += m;
        }else{
            sum += it.second;
        }
    }
    int ans = val - sum;
    return ans;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        int m;
        cin>>n>>m;
        string s;
        cin>>s;
        cout<<solve(m,n,s)<<endl;
    }
}