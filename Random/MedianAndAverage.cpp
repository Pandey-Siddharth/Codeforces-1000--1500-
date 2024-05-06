#include<iostream>
#include<vector>
//#include<bits/stdc++.h>

using namespace std;

double maxSum(vector<double>&arr,int i,int flag, vector<vector<double> >&dp){
    if(i <= 0){
        if(arr[i]>=0 || flag == 0){
            return arr[i];
        }else{
            return 0;
        }
    }
    if(dp[i][flag]!=-1) return dp[i][flag];

    double take = arr[i] + maxSum(arr,i-1,1,dp);
    double not_take = INT_MIN;
    if(flag){
        not_take = maxSum(arr,i-1,0,dp);
    }
    return dp[i][flag] = max(take,not_take);
}

double bestAverage(vector<long long> arr, int n)
{
    double left = 0, right = 1e12;
    double error = 1e-5;
    double avg;
    // SS - log2(10^17)
    for (int iterations = 0; iterations <= 100; iterations++)
    {
        double mid = (left + right) / 2;
        vector<double> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i] = arr[i] - mid;
        }
        vector<vector<double> >dp(n,vector<double>(2,-1));
        if (maxSum(temp, n-1,1,dp) >= 0)
        {
            avg = mid;
            left = mid + error;
        }
        else
        {
            right = mid - error;
        }
    }
    return avg;
}
int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << bestAverage(arr, n) << endl;

}