#include<bits/stdc++.h>

using namespace std;


vector<int> solve(vector<int>arr,int k){
    multiset<int> st;
    vector<int> ans;
    for(int i=0;i<arr.size();i++){
        st.insert(arr[i]);
        if(i > k-1){
            st.erase(st.find(arr[i-k]));
        }
        if(i >= k-1){
            auto it = next(st.begin(),k/2);
            if(k % 2 ==0){
                ans.push_back(min(*it,*prev(it)));
            }else{
                ans.push_back(*it);   
            }
        }
    }
    return ans;
}


int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &it:arr){
        cin>>it;
    }
    vector<int> ans(n-k+1);
    ans = solve(arr,k);
    for(auto it:ans){
        cout<<it<<" ";
    }
}