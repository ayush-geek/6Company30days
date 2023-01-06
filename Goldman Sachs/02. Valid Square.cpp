class Solution {
public:

//Submission:-> https://leetcode.com/problems/valid-square/submissions/872572067/

    long dist(pair<int,int>& a,pair<int,int>& b)
    {
        return pow((b.first-a.first),2) +pow((b.second-a.second),2);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        
        //a ,b
        //a,c,
        //a,d


        //Chk slope
        //And length

       vector<pair<int,int>> vp;

       vp.push_back({p1[0],p1[1]});
       vp.push_back({p2[0],p2[1]});
       vp.push_back({p3[0],p3[1]});
       vp.push_back({p4[0],p4[1]});

      
        sort(vp.begin(),vp.end());

         if(vp[0]==vp[1] || vp[1]==vp[2]|| vp[2]==vp[3])
            return false;
    cout<<vp[0].first<<" "<<vp[0].second<<endl;
    cout<<vp[1].first<<" "<<vp[1].second<<endl;

    cout<<vp[2].first<<" "<<vp[2].second<<endl;
    cout<<vp[3].first<<" "<<vp[3].second<<endl;

    map<int,int> mp;

       int lab=dist(vp[0],vp[1]);
       int lbc=dist(vp[1],vp[2]);
       int lcd=dist(vp[2],vp[3]);
       int lda=dist(vp[3],vp[0]);

       int lac=dist(vp[0],vp[2]);
       int lbd=dist(vp[1],vp[3]);

       mp[lab]++;
       mp[lbc]++;
       mp[lcd]++;
       mp[lda]++;
       mp[lac]++;
       mp[lbd]++;
       if(mp.size()==2)
        return true;

        return false;


    }
};