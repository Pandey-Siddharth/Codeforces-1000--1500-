#include<iostream>
#include<vector>
//#include<bits/stdc++.h>

using namespace std;

int check(vector<int> &arr, int k) {
    int n = arr.size();
    int i = k - 1;
    bool flag = true;
    for (int j = n - 1; i >= 0; j--, i--) {
        if (arr[i] < arr[j] and arr[i] < arr[j - 1]) {
            flag = true;
        } else {
            flag = false;
            break;
        }
    }
    return flag;
}
int solve(vector<int> &arr,int n){
    int low = 0;
    int high = (n-1)/2;
    int ans = 0;
    while(low<=high){
        int mid = (high+low)/2;
        if(check(arr,mid)){
            low = mid+1;
            ans = mid;
        }else{
            high = mid -1;
        }
    }
    return ans;
}
vector<int> print(vector<int> &a,int k,int n){
    int i = k-1;
    int j = n-1;
    vector<int> ans(n);
    for(int k= 0;k<n;k++){
       if(k%2 != 0 && i >= 0){
        ans[k] = a[i--];
       }else{
        ans[k] = a[j--];
       }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int ans = solve(arr,n);
    vector<int> f = print(arr,ans,n);
    cout<<ans<<endl;
    for(auto it:f){
        cout<<it<<" ";
    }
}