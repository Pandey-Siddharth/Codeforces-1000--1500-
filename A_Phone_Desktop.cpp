#include<bits/stdc++.h>

using namespace std;

int solve(double x,double y){
    double b = ceil(y/2);
    x = x - (7 * b);
    if((int)y%2 == 1){
        x -= 4;
    }
    double a = 0;
    if(x>0)
    {a = ceil(x/15);}
    return b+a;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        double x,y;
        cin>>x>>y;
        cout<<solve(x,y)<<endl;
    } 
}
// if(y < 2){
    //      a = ceil(x/(15 - (4 * y)));
    // }else{
    //     a = ceil(x/7);
    // }