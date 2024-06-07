
#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(vector<int>& mainVec, vector<int>& subVec) {
    if(subVec.empty()) return true;  // An empty subsequence is always a subsequence
    if(mainVec.size() < subVec.size()) return false;  // If main vector is smaller than subsequence, it's not possible

    int mainIndex = 0;
    int subIndex = 0;
    int t = INT_MAX;
    int g = 0;

    while(mainIndex < mainVec.size() && subIndex < subVec.size()) {
        if(mainVec[mainIndex] == subVec[subIndex]) {
            if(g == 0){t = mainIndex;}
            subIndex++;
            g++;
        }
        mainIndex++;
    }

    // If we've gone through the entire subVec, then it's a subsequence
    return (subIndex == subVec.size() && t == 0);
}

void solve(vector<int> a,vector<int> b,int n,vector<int> c){
    vector<int>temp;
    for(int i=0;i<n;i++){
        if(a[i] != b[i]){
            temp.push_back(b[i]);
        }
    }
    vector<int>temp2 = c;
    reverse(temp2.begin(),temp2.end());
    if(isSubsequence(c,temp) || isSubsequence(temp2,temp)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);
        for(auto &it:a){
            cin>>it;
        }
        for(auto &it:b){
            cin>>it;
        }
        int m;
        cin>>m;
        vector<int>c(m);
        for(auto &it:c){
            cin>>it;
        }
        solve(a,b,n,c);        
    }
}