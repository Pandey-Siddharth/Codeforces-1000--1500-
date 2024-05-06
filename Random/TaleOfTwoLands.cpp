#include<iostream>
#include<vector>
//#include<bits/stdc++.h>

using namespace std;

long long solve(vector<long long> &arr,int n){
    long long ans = 0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        auto it = upper_bound(arr.begin(),arr.end(),2 * arr[i]);
        it--;
        ans = ans + ((it - arr.begin()) - i);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i] = abs(arr[i]);
    }
    long long ans = solve(arr,n);
    cout<<ans<<endl;
}