#include<iostream>
#include<vector>

using namespace std;

vector<int> solve(vector<int> arr, int n,vector<int> juicy){
    vector<int> temp;
    for(int i=0;i<juicy.size();i++){
        int low = 0;
        int high = n-1;
        int ans = 0;
        while(low <= high){
            int mid = (high + low)/2;
            if(arr[mid] >= juicy[i]){
                ans = mid;
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
        temp.push_back(ans+1);
    }
    return temp;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int j;
    cin>>j;
    vector<int>juicy(j);
    for(int i=0;i<j;i++){
        cin>>juicy[i];
    }
    for(int i=1;i<n;i++){
        arr[i] = arr[i] + arr[i-1];
    }
    vector<int> ans = solve(arr,n,juicy);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}