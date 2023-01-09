#include <bits/stdc++.h>

using namespace std;

long long solve(int i,int j,vector<vector<long long>>& dp,vector<int>& v)
{
    if(i<0)
        return 0;

    if(j==0)
        return 1;
    
    if(i==0)
    {
        if(j%v[0]==0)
            return 1;
        return 0;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];

    long long tk=0;
    if(v[i]<=j)
        tk=solve(i,j-v[i],dp,v);
    long long nt=solve(i-1,j,dp,v);
        
    return dp[i][j]=tk+nt;
}


int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> v;

    int num;

    for(int i=0;i<n;i++)
    {
        cin>>num;
        v.push_back(num);
    }


    vector<vector<long long>> dp(n,vector<long long> (k+1,-1));


    cout<<solve(n-1,k,dp,v)<<"\n";
}