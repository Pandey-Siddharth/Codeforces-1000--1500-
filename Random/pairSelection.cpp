#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std ;


bool check(vector<pair<int,int> > &arr,double mid,int k){
    vector<double> c;
    for(auto it : arr){
        double t = it.first - mid*it.second;
        c.push_back(t);
    }
    sort(c.begin(),c.end());
    double sum = 0;
    int n = c.size();
    for(int i=0;i<k;i++){
        sum += c[n-i-1];
        //if(sum>=0)
    }
    return sum>=0 ? true : false;
}

double solve(vector<pair<int,int> > &arr,int k){
    double precesion = 1e-7;
    double low = precesion;
    double high = 1e7;
    double ans = 0;
    for (int iterations = 0; iterations < 60; iterations++){
        double mid = (high + low)/2;
        if(check(arr,mid,k)){
            ans = mid;
            low = mid+precesion;
        }else{
            high = mid-precesion;
        }
    }
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int> > arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
   // cout << setprecision(9) << fixed << solve(arr,k) <<endl;
    return 0;
}
// cout << setprecision(7) << fixed << solve(arr,k) <<endl;