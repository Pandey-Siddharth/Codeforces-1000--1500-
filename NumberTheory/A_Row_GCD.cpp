#include<bits/stdc++.h>

using namespace std;

vector<long long> solve(vector<long long>a,vector<long long>b){
    vector<long long>ans(b.size());
    long long pre = 0;
    for(int i=1;i<a.size();i++){
        pre = __gcd(pre,abs(a[i]-a[0]));
    }
    for(int i=0;i<b.size();i++){
        ans[i] = __gcd((a[0]+b[i]),pre);
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<long long>a(n);
    vector<long long>b(m);
    for(auto &it:a){
        cin>>it;
    }
    for(auto &it:b){
        cin>>it;
    }
    vector<long long>ans = solve(a,b);
    for(auto it:ans){
        cout<<it<<" ";
    }
}