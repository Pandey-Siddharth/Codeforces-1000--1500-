#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr){
    vector<int>mpp(200001,0);
    for(int i=0;i<arr.size();i++){
        if(arr[i]>200000){continue;}
        mpp[arr[i]]++;
    }
    vector<int>trapped(arr.size()+1,0);
    for(int i=1;i<=arr.size();i++){
        for(int j=i;j<=arr.size();j+=i){
            trapped[j] += mpp[i];
        }
    }
    int ans = 0;
    for(int i=1;i<=arr.size();i++){
        ans = max(ans , trapped[i]);
    }
    return ans;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        long long n;
        cin>>n;
        vector<int>arr(n);
        for(auto &it:arr){
            cin>>it;
        }
        cout<<solve(arr)<<endl;
    }
}