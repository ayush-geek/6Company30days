class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //Solution :->https://leetcode.com/problems/course-schedule/submissions/869771717/
        //qustion is of Toplogy Sort

        int n=numCourses;


        vector<int> adj[n];
        vector<int> indeg(n,0);


        for(int i=0;i<prerequisites.size();i++)
        {
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];


            adj[b].push_back(a);
            indeg[a]++;

        }
        

        queue<int> q;
        for(int i=0;i<n;i++)
        {

            if(indeg[i]==0)
                q.push(i);

        }


        while(!q.empty())
        {
            int z1=q.front();
            q.pop();
            for(auto ele: adj[z1])
                {
                    indeg[ele]--;
                    if(indeg[ele]==0)
                        q.push(ele);
                }
        }

        for(int i=0;i<n;i++)
        {
            if(indeg[i]!=0)
                return false;
        }
        return true;
    }
};