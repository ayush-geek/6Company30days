class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        // Submission:->https://leetcode.com/problems/max-points-on-a-line/submissions/873979422/
        //Use Computer Graphics

        // Just  slope


        unordered_map<float,int> mp;
        int ans=0;
        int n=points.size();
        for(int i=0;i<n;i++)
        {   
             unordered_map<float,int> mp;
            for(int j=i+1;j<n;j++)
            {
                
                   

                    float zy=(points[i][1]-points[j][1]);
                    float zx=(points[i][0]-points[j][0]);

                    if(zx==0)
                    {
                          mp[INT_MAX]++;
                           ans=max(ans,mp[INT_MAX]);
                    }
                       
                   else{
                    mp[zy/zx]++;


                    //cout<<zy/zx<<" "<< mp[zy/zx]<<endl;
                    ans=max(ans,mp[zy/zx]);
                   }
              
            }
        }

        return ans+1;
    }
};

