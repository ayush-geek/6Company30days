class Solution {
public:
    string getHint(string secret, string guess) {
        

        //Solution:-> https://leetcode.com/problems/bulls-and-cows/submissions/868938607/
        int n=secret.size();
        int a=0;
        int b=0;

        vector<int> v1(10,0);
        vector<int> v2(10,0);

        for(int i=0;i<n;i++)
        {

            if(secret[i]==guess[i])
                a++;
            else
            {
                v1[secret[i]-'0']++;
                v2[guess[i]-'0']++;
            }
        }

        for(int i=0;i<10;i++)
        {
            b+=min(v1[i],v2[i]);
        }

       // cout<<a<<" "<<b<<endl;
       string res=to_string(a)+"A"+to_string(b)+"B";

       return res;

    }
};