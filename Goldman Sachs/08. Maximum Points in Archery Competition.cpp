class Solution {
public:
    vector<int> ans;
    int tgt=0;
  
    void solve(int i,int j,vector<int>& alice,vector<int>& res,int sm)
    {

        if(i==12 ||j<=0)
        {   
            
            if(sm>tgt){
                tgt=sm;
               
                ans=res;
                
            
            }
            
          
            return ;
        }
        
        int k=i;
        //for(int k=i;k<12;k++)
        {
            //take
            if(j>=1+alice[k])
            {
            res[k]=1+alice[k];
            solve(k+1,j-alice[k]-1,alice,res,sm+k);
            res[k]=0;
            }

            //Not take
            solve(k+1,j,alice,res,sm);

        }


    }    



    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        

        //eASY tAKE IT or not take


        vector<int> res(12,0);
      
        int sm=0;
       solve(0,numArrows,aliceArrows,res,0);

        // cout<<arr<<endl;
         int arrows_used = 0; 
        for(int a : ans)
            arrows_used += a; 
        if(arrows_used < numArrows)
            ans[0] += (numArrows - arrows_used);

        return ans;

    }
};