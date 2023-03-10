class Solution {
public:
    int m=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        
        //Submission:->https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/submissions/871095198/
        //Dijkstra Algorithm

        
        vector<pair<long long,long long>> adj[n];


        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});


        }

        vector<long long> dist(n,LONG_MAX);
        vector<long long> path(n,0);


        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;

        pq.push({0,0});
        dist[0]=0;
        path[0]=1;

        while(!pq.empty())
        {
            long long dis=pq.top().first;
            long long ed=pq.top().second;

            pq.pop();

            for(auto it: adj[ed])
            {
                
                if(dis+it.second<dist[it.first])
                {
                    dist[it.first]=(dis+it.second);

                    pq.push({dist[it.first],it.first});
                    path[it.first]=path[ed];
                }

                else if(dis+it.second==dist[it.first])
                {
                    
                    path[it.first]=(path[ed]+path[it.first])%m;
                }
                
            }
        }

        return path[n-1];

    }
};