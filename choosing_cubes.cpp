#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>arr,int f,int k){
    int fav = arr[f];
    sort(arr.rbegin(),arr.rend());
    int first = 0;
    int last = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == fav){
            first = i+1;
            break;
        }
    }
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i] == fav){
            last = i+1;
            break;
        }
    }
    if(first > k && last > k){
        cout<<"NO"<<endl;
        return;
    }
    else if(first <= k && last <= k){
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"MAYBE"<<endl;
        return;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,f,k;
        cin>>n>>f>>k;
        vector<int>arr(n);
        for(auto &it:arr){
            cin>>it;
        }
        solve(arr,f-1,k);
    }
}