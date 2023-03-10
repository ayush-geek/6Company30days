class Solution {
public:
    int numberOfSubstrings(string s) {
        

        //Sliding Window

        //Submission:->https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/870665898/
        int i=0;
        int j=0;
        vector<int> v(3,0);
        int n=s.size();
        int ans=0;
        for(i=0;i<n;i++)
        {
            v[s[i]-'a']++;


            while(v[0] && v[1] && v[2] && j<=i)
            {
                v[s[j]-'a']--;

                ans+=(n-i);
                j++;
            }

        }

        return ans;
    }
};