class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        

        //Submission:->https://leetcode.com/problems/rotate-function/submissions/870581402/
        //f(k)=f(k-1) + sum -N*(nums[n-k]);

        int n=nums.size();
        vector <int> dp(n,0);

        int ans=0;
        int sm=0;
        for(int i=0;i<n;i++){
            ans+=i*nums[i];
            sm+=nums[i];
            }
        dp[0]=ans;
        int mx=ans;
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1]+sm-nums[n-i]*n;

            //cout<< dp[i]<<endl;
            mx=max(mx,dp[i]);
        }

        return mx;
    }
};