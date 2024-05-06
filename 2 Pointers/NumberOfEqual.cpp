#include<bits/stdc++.h>

using namespace std;

long long solve(vector<long long> a,vector<long long> b,int n,int m){
    int i = 0;
    int j = 0;
    long long count = 0;
    while(i <n && j < m){
        if(a[i] == b[j]){
            long long a1 = a[i];
            long long num1 = 0;
            long long num2 = 0;
            while(i < n && a[i] == a1){
                num1++;
                i++;
            }
            while(j < m && b[j] == a1){
                num2++;
                j++;
            }
            
            count += (num1*num2);
        }
        else if(i<n && j<m && a[i] > b[j]){
            j++;
        }
        else{
            i++;
        }
        
    }
    return count;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<long long>a(n);
    vector<long long>b(m);
    for(auto &it:a){
        cin>>it;
    }
    for(auto &it:b){
        cin>>it;
    }
    cout<<solve(a,b,n,m);
}