class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>>mp;
        int m = mat.size(), n = mat[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        for(auto &x: mp)
        {
            vector<int> t = x.second;
            if(x.first%2==0)
            {
                reverse(t.begin(),t.end());
            }
            for(auto y: t)
            ans.push_back(y);
        }
        return ans;
    }
};