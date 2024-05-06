#include<iostream>
#include<vector>
#define int int64_t
using namespace std;

bool check(vector<double> &arr,double length,int target){
    int pieces = 0;
    for(int i=0;i<arr.size();i++){
        pieces += arr[i]/length;
    }
    return pieces >= target ? true : false;
}

double solve(vector<double> &arr, int target){
    double low = 1e-7;
    double high = 1e7;
    double p = 1e-7;
    double ans;
    while(high - low > p){
        double mid = (high + low)/2;
        if(check(arr,mid,target)){
            ans = mid;
            low = mid+p;
        }else{
            high = mid-p;
        }
    }
    return ans;
}
signed main(){
    int n,k;
    cin>>n>>k;
    vector<double> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,k);
    return 0;
}