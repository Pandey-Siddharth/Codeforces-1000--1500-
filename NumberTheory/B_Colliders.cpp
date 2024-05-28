#include<bits/stdc++.h>
using namespace std;

int N = 100001;
vector<int>colliders(N,0);
vector<int>isActive(N,0);
vector<int>spf(N);

vector<int>prime(int n){
    vector<int>ans;
    while(n != 1){
        int x = spf[n];
        while(n % x == 0){
            n = n/x;
        }
        ans.push_back(x);
    }
    return ans;
}
void seive(){
    for(int i=0;i<N;i++){
        spf[i] = i;
    }
    for(int i=2;i<N;i++){
        for(int j=2*i;j<N;j+=i){
            if(spf[j] == j) spf[j] = i;
        }
    }
}

void solve(char sign,int n){
    vector<int>primes  = prime(n);
    if(sign == '+'){
        if(isActive[n]) cout<<"Already on"<<endl;
        else{
            int collisions = 0;
            for(auto &it: primes){
                if(colliders[it]) collisions = colliders[it];
            }
            if(collisions) cout<<"Conflict with "<<collisions<<endl;
            else{
                cout<<"Success"<<endl;
                for(auto &it:primes){
                    colliders[it] = n;
                }
                isActive[n] = 1;
            }
        }
    }
    if(sign == '-'){
        if(isActive[n] == 0) cout<<"Already off"<<endl;
        else{
            cout<<"Success"<<endl;
            for(auto &it:primes){
                colliders[it] = 0;
            }
            isActive[n] = 0;
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    seive();
    for(int i=0;i<m;i++){
        char c;
        int t;
        cin>>c>>t;
        solve(c,t);
    }
    return 0;
}
