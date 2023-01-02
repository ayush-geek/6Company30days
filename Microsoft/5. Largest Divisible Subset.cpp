class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        


        //Submission:-> https://leetcode.com/problems/largest-divisible-subset/submissions/869560150/
        vector<int> res;
        sort(nums.begin(),nums.end());


        int n=nums.size();

        vector<int> dp(n,1);
        vector<int> hash(n,0);
        int lpos=0;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && (1+dp[j]>dp[i]))
                {
                    dp[i]=1+dp[j];
                    hash[i]=j;

                    if(dp[i]>mx)
                    {
                        mx=dp[i];
                        lpos=i;
                    }
                    // lpos=i;

                }
            }
        }

        res.push_back(nums[lpos]);

        while(hash[lpos]!=lpos)
        {
            lpos=hash[lpos];

            res.push_back(nums[lpos]);
        }

        reverse(res.begin(),res.end());

        return res;


    }
};