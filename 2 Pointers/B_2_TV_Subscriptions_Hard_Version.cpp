
#include<bits/stdc++.h>

using namespace std;

long long solve(vector<int> &arr,int d,int n){
    long long ans = LLONG_MAX;
    long long sum = 0;
    unordered_map<int,int> mpp;

    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        if(i > d-1){
            mpp[arr[i-d]]--;
            if(mpp[arr[i-d]] == 0){
                mpp.erase(arr[i-d]);
            }
        }
        if(i >= d-1){
            ans = min(ans,(long long)mpp.size());
        }
    }
    return ans;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,k,d;
        cin>>n>>k>>d;
        vector<int> arr(n);
        for(auto &it:arr){
            cin>>it;
        }
        cout<<solve(arr,d,n)<<endl;
    }
}