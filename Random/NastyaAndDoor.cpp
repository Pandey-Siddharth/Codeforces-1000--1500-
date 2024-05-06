#include<bits/stdc++.h>

using namespace std;

vector<long> solve(vector<int> arr, int k){
    multiset<int> st;
    int n = arr.size();
    int j = 1;
    int ans = 0;
    int l = 0;
    for(int i=0;i<n;i++){
        if(st.find(arr[i]) != st.end() && arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            st.erase(st.find(arr[i]));
        }
        while(i+k <= n && j < i+k-1){
            if(arr[j] > arr[j-1] && arr[j] > arr[j+1]){
                st.insert(arr[j]);
            }
            j++;
        }
        if((int)st.size() > ans){
            ans = (int)st.size();
            l = i;
        }
    }
    return {ans+1,l+1};
}
int main(){
    int t;
    cin>>t;
        while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(auto &it:arr){
            cin>>it;
        }
        vector<long>ans(2);
        ans = solve(arr,k);
        cout<<ans[0]<<" "<<ans[1]<<endl;
        }
}