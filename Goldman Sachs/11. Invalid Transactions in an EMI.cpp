class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        
        int n=transactions.size();
        vector<string> res;
        vector<string> v[n];
        for(int i=0;i<n;i++)
        {
           
            stringstream ss(transactions[i]);
            while(ss.good())
            {
                string substr;
                getline(ss, substr, ',');
                v[i].push_back(substr);
            }

        }


        for(int i=0;i<n;i++)
        {

            if(stoi(v[i][2])>1000)
                res.push_back(transactions[i]);

            else
            {
                for(int j=0;j<n;j++)
                {
                    if(j==i) continue;

                    if(v[i][0]==v[j][0] && v[i][3]!=v[j][3] )
                        {
                            
                            if(abs(stoi(v[i][1])-stoi(v[j][1]))<=60)
                            {
                                cout<<abs(stoi(v[i][1])-stoi(v[j][1]))<<endl;
                                res.push_back(transactions[i]);
                                break;
                            }
                            
                            
                        }
                }
            }
        }









        return res;
    }
};