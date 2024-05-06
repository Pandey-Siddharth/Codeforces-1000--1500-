#include<vector>
 #include<iostream>

using namespace std;

long long solve(vector<long long> arr,int k,int n){
    long long ans = 0;
    long long sum = 0;
    long long  j = 0;
    for(int i=0;i<n;i++){
        while(j < n && sum + arr[j] <= k){
            sum += arr[j];
            j++;
        }
        long long  length = (j-i);
        ans += (length * (length+1))/2;
        sum -= arr[i];
    }
    return ans;
}
int main(){
    long long n,k;
    cin>>n>>k;
    vector<long long>arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    cout<<solve(arr,k,n);
    return 0;
} 