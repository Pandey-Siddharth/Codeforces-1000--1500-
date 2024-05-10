#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long solve(vector<int> arr,long long k,int n){
    long long sum = 0;
    long long ans = 1e-9;

    for(int i=0,j=0;i<n;i++){
        while(j < n && sum + arr[j] <= k){
            sum += arr[j];
            j++;
        }
        if(sum <=k ){
            ans = max(ans,(long long)(j-i));
        }
        sum -= arr[i];
    }
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    cout<<solve(arr,k,n)<<endl;
}