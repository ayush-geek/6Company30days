class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
//Submission :-> https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/submissions/874045340/

        int ans=INT_MAX;
        unordered_map<int,int> mp;
        int n=cards.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(cards[i])!=mp.end())
            {
                ans=min(ans,i-mp[cards[i]]+1);
          
            }
            
                mp[cards[i]]=i;
            
        }

        if(ans==INT_MAX)
            return -1;

        return ans;
    }
};