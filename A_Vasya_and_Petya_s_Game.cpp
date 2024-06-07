#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr,int a){

}
int main(){
    int n;
    cin>>n;
    vector<int> queries;
    vector<int> isPrime(n+1,1);
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j = j+i){
                isPrime[j] = 0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            int number = i;
            while(number <= n){
                queries.push_back(number);
                number = number * i;
            }
        }
    }
    cout<<queries.size()<<endl;
    for(auto it : queries){
        cout<<it<<" ";
    }
    return 0;
}