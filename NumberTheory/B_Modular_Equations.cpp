#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    long long count = 0;
    if(b>a){
        cout<<0<<endl;
        return 0;
    }
    if(a == b){
        cout<<"infinity";
        return 0;
    }
    for(int i=1;i*i<=(a-b);i++){
        if((a-b)%i == 0){
            if(i > b) count++;
            if((a-b)/i>b && (a-b)/i !=i) count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
