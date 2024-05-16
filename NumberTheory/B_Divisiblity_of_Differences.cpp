#include<bits/stdc++.h>

using namespace std;

int main(){
        int n,k,m;
        cin>>n>>k>>m;
        vector<int>arr(n);
        map<int,int>mpp;
        multiset<int>st;
        for(auto &it:arr){
            cin>>it;
            mpp[it % m]++;
        }
        for(auto &[mod,count]:mpp){
            if(count >= k){
                cout<<"Yes"<<endl;
                for(auto it : arr){
                    if(it % m == mod && k >0){
                        cout<<it<<" ";
                        k--;
                    }
                }
                return 0;
            }
        }
        cout<<"No"<<endl;
}

