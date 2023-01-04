class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        //Solution link ->  https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/868898948/
        //Approach
        //Use Stack
        /*If Operands than pop the top 2elements in 
            the stack do
            the opertion ans push in stack
        */
        /*
        else
            push into stack
        */


        stack<int> st;

        for(int i=0;i<tokens.size();i++)
        {   
            
            if(tokens[i]=="+")
            {
                int e1=st.top(); st.pop();
                int e2=st.top(); st.pop();

                st.push(e1+e2);
            }
            else  if(tokens[i]=="-")
            {
                int e1=st.top(); st.pop();
                int e2=st.top(); st.pop();

                st.push(e2-e1);
            }

            else  if(tokens[i]=="*")
            {
                int e1=st.top(); st.pop();
                int e2=st.top(); st.pop();

                st.push(e2*e1);
            }

            else  if(tokens[i]=="/")
            {
                int e1=st.top(); st.pop();
                int e2=st.top(); st.pop();

                st.push(e2/e1);
            }
            else
            {
                int z=stoi(tokens[i]);

                st.push(z);
            }
            
        }

        return st.top();

    }
};
