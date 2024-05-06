#include<iostream>
#include<vector>
//#include<bits/stdc++.h>

using namespace std;

bool check(vector<int>&arr,long long mid,long long k,long long sum,int n){
    long long sufix_l = min((long long)n-1,mid-1);
    if(sum - mid<=k) return true;
    long long suffix_sum = 0;
    long long fs = 1e9;
    //if(sufix_l <1) fs = sum - mid;
    for(long long i=1;i<=sufix_l;i++){
        suffix_sum += arr[n-i];
        fs = sum - arr[0] - suffix_sum + ((i+1) * (arr[0]-(mid - i)));
        if(fs <= k){
            return true;
        }
    }

    return fs<=k?true:false;
}
int solve(vector<int>&a,long long sum,int n,long long k){
    long long low = 0;
    long long high = 1e15;
    long long ans = 0;
    while(low<=high){
        long long mid = (high+low)/2;
        if(check(a,mid,k,sum,n)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        long long sum = (long long)0;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum += arr[i];
        }
        sort(arr.begin(),arr.end());
        long long ans = solve(arr,sum,n,k);
        cout<<ans<<endl;
    }
}