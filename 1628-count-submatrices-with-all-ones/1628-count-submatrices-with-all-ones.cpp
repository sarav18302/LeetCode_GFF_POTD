class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rowDP(n,0);
        int total = 0;
        for(int i =0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(mat[i][j] == 1)
                {
                    rowDP[j]++;
                    int k = j-1;
                    int ref = rowDP[j];
                    total+=rowDP[j];
                    while(k>=0 && mat[i][k] >0)
                    {
                        ref = min(ref,rowDP[k]);
                        total+=ref;
                        k--;
                    }
                }
                else
                {
                    rowDP[j] = 0;
                }
            }
        }
        return total;
    }
};