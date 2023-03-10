/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void solve(TreeNode* rt,vector<int>& v)
    {
        if(rt==NULL)
            return ;

        solve(rt->left,v);
        v.push_back(rt->val);
        solve(rt->right,v);
    }


    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        

        vector<int> res1;
        vector<int> res2;
        vector<int> res;
        solve(root1,res1);
        solve(root2,res2);

        int i=0 ,j=0;
        while(i<res1.size() && j<res2.size())
        {
            if(res1[i]<=res2[j])
            {
                res.push_back(res1[i++]);
            }
            else
            {
                res.push_back(res2[j++]);
            }
        }
        if(i<res1.size())
        {
            for(int k=i;k<res1.size();k++)
                res.push_back(res1[k]);
        }


        if(j<res2.size())
        {
            for(int k=j;k<res2.size();k++)
                res.push_back(res2[k]);
        }
        return res;
    }
};