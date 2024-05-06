//#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

bool check(vector<int>arr,int mid){
    int n = arr.size();
    vector<int> a(n);
    for(int i=0;i<n;i++){
        a[i] = arr[i];
    }
    for(int i = arr.size()-1;i>=0;i--){
        if(a[i]<mid){
            return false;
        }
        else{
            int y = min(arr[i]/3,(a[i]-mid)/3);
            a[i] -= 3*y;
            if(i > 1){
                a[i-1] += y;
                a[i-2] += 2*y; 
            }
        }
    }
    return true;
}
int solve(vector<int>arr,int n){
    int high = 1e9;
    int low = 0;
    int ans = 0;
    while(low<=high){
        int mid = (high+low)/2;
        if(check(arr,mid)){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = solve(arr,n);
    cout<<ans<<endl;
    }
}


