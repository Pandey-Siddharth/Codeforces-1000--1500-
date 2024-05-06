#include<iostream>
#include<vector>
#define int int64_t
using namespace std;

bool check(int val,int n){
    int count = 0;
    for(int i=1;i<=n;i++){
        count += min(n,val/i);
    }
    int total = n*n;
    return count >= (total/2) + 1 ? true : false;
}

int solve(int n){
    int low = 1;
    int high = n*n ;
    int ans = 0;
    while(low<=high){
        int mid = (high+low)/2;
        if(check(mid,n)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

signed main(){
    int n;
    cin>>n;
    cout << solve(n) << endl;
    return 0;
}