class Solution {
public:


    //Submission:-> https://leetcode.com/problems/number-of-boomerangs/submissions/872773079/
    long long dist(vector<int>& a,vector<int>& b)
    {

        return (b[1]-a[1])*(b[1]-a[1]) +(b[0]-a[0])*(b[0]-a[0]);

    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int c=0;
        int n=points.size();

        for(int i=0;i<n;i++)
        {   unordered_map<int,int> mp;
            for(int j=0;j<n;j++)
            {   
                
                if(j==i)    
                    continue;
                else
                {
                    mp[dist(points[i],points[j])]++;
                }
            }

            for(auto it: mp)
            {   
               
                int z=it.second;
                c+=(z*(z-1));
            }



        }


        return c;
    }
};