#include<iostream>
#include<vector>
#define int int64_t
using namespace std;
 
// bool pred(vector<int> arr,int targetTime,int targetP){
//    int numOfProducts = 0;
//    for(int i=0;i<arr.size();i++){
//     numOfProducts += targetTime/arr[i];
//     if(numOfProducts >= targetP) return true;
//    }
//    return numOfProducts >= targetP;
// }
 bool pred(vector<int> arr,int target,int targetP){
    int n = arr.size();
    int i = 0;
    int count = 0;
    while(i < n ){
        count += (target/arr[i]);
        if(count >= targetP) return true;
        i++;
    }
    if(count >= targetP){
        return true;
    }
    return false;
 }
 
int bs (vector<int> &arr, int target){
    int low = 0;
    int high = 1e18;
    int ans = 0;
    while(low<=high){
        int mid  = (high + low)/2;
        if(pred(arr,mid,target)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
 
signed main(){
    int n,t;
    cin>>n>>t;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<bs(arr,t);
    return 0;
}