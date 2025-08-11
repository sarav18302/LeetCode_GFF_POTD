class Solution {
public:
    int mod = 1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int i =0;
        while(n >= (1<<i))
        {
            if(n & (1<<i))
            powers.push_back((1<<i));
            i++;
        }
        vector<int> ans;
        for(auto query:queries)
        {
            long long t = 1;
            for(int i = query[0];i<=query[1];i++)
            {
                t =(t*powers[i])%mod;
            }
            ans.push_back(t);
        }
        return ans;
    }

};