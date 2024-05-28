#include<bits/stdc++.h>

using namespace std;

long long solve(vector<vector<int> > arr,int n,int m){
    long long ans = 0;
    for(int i=0;i<n;i++){
        long long c1 = 0;
        long long c2 = 0;
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0) {c1++;}
            else{c2++;}
        }
    ans += ((1LL<<(c1))-1) + ((1LL<<(c2))-1);
    }
    for(int i=0;i<m;i++){
        long long c1 = 0;
        long long c2 = 0;
        for(int j=0;j<n;j++){
            if(arr[j][i] == 0){c1++;}
            else{c2++;}
        }
        ans += ((1LL<<(c1))-1) + ((1LL<<(c2))-1);
    } 
    return ans - n*m;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> >arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<solve(arr,n,m)<<endl;
}