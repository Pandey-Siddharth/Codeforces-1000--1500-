#include<bits/stdc++.h>
#include <numeric>

using namespace std;

int gcd(int a, int b){
    if (b == 0)
       return a;
    return gcd(b, a % b); 
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        long long n;
        cin>>n;
        vector<int> arr(n);
        for(auto &it:arr){
            cin>>it;
        }
        int x = 0;
        for(int i=0;i<n;i++){
            x = gcd((int)x,(int)abs(arr[i] - arr[n-i-1]));
        }
        cout<<x<<endl;
    }
}