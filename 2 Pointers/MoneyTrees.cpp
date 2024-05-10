#include<iostream>
#include<vector>

 using namespace std;

 long long solve(vector<int> arr,vector<int> h,int k,int n){
    long long ans = 0;
    long long sum = 0;
    int i = 0;
    int j = 0;
    while(i<n){
        while((j+1 < n && sum + arr[j] <= k) && h[j] % h[j+1] == 0){
            sum += arr[j];
            j++;
        }
        if(sum + arr[j] <= k ){
            ans = max(ans,(long long)(j-i+1));
        }else{
            ans = max(ans,(long long)j-i);
        }
        if(j<n-1 && h[j] % h[j+1] != 0){
            sum = 0;
            j++;
            i = j;
        }else{
            sum -= arr[i];
            i++;
        }
    }
    return ans;
 }

 int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        vector<int> h(n);
        for(auto &it: arr){
            cin>>it;
        }
        for(auto &i: h){
            cin>>i;
        }
        cout<<solve(arr,h,k,n)<<endl;
     }
 }