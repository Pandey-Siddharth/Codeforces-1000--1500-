#include<bits/stdc++.h>
using namespace std;
 
long long solve(vector<int>arr,int n,int k){
    unordered_map<int,int> mpp;
    long long ans = 0;
    for(int i=0,j=0;i<n;i++){
        if(i>0 && k>0){
            mpp[arr[i-1]]--;
            if(mpp[arr[i-1]] == 0){
                mpp.erase(arr[i-1]);
            }
        }
       while (j < n && (mpp.size() < k || mpp.find(arr[j]) != mpp.end())){
            mpp[arr[j]]++;
            j++;
        }
        ans += (j-i);
    }
    return ans<0 ? 0 : ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto &it:arr){
        cin>>it;
    }
 
    cout<<solve(arr,n,k);
}