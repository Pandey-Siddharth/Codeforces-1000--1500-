#include<bits/stdc++.h>

using namespace std;

long long M = 1e9 +7;

// long long divide(long long a,long long b){
//    long long p = (a,power())
// }

long long solve(vector<int> &arr,int m,int n,unordered_map<int,int> &mpp){
    long long count = 1;
    long long ans = 0;
    for(int i =0,j=0;i<n;i++){
        while(j < arr.size() && arr[j] < arr[i] + m){
           count = (count * mpp[arr[j]]) % M;
            j++;
        }
        if(j - i == m){
            ans = (ans + count) % M;
        }
        count = count/mpp[arr[i]];
    }
    return ans ;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        set<int>s;
        vector<int> arr(n);
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            s.insert(arr[i]);
            mpp[arr[i]]++;
        }
        vector<int>distinct(s.begin(),s.end());
        cout<<solve(distinct,m,n,mpp)<<endl;
    }
}