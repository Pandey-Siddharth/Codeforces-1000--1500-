#include<bits/stdc++.h>

using namespace std;

string solve(string &arr){
    string ans = "";
    string odd = "",even = "";
    for(auto it: arr){
        if(it%2 == 0){
            even += it;
        }else{
            odd += it;
        }
    }
    int i = 0,j = 0;
    while(i < even.size() && j < odd.size()){
        if(even[i]-'0'<odd[j]-'0'){
            ans += even[i++];
        }else{
            ans += odd[j++];
        }
    }
    while(i < even.size()){
        ans += even[i++];
    }
    while(j < odd.size()){
        ans += odd[j++];
    }
    return ans;
}


int main(){
    int tt;
    cin>>tt;
    while(tt--){
        string arr;
        cin>>arr;
        cout<<solve(arr)<<endl;
    }
}