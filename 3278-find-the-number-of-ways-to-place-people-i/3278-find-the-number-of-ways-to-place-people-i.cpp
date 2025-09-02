class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;
        for(int i =0;i<n;i++)
        {
            int x = points[i][0], y = points[i][1];
            for(int j = 0;j<n;j++)
            {
                if(i==j) continue;
                int a = points[j][0], b = points[j][1];
                bool flag = true;
                if(y>=b &&x<=a)
                {
                    for(int k =0;k<n;k++)
                    {
                        if(k==i || k ==j)
                        continue;
                        int p = points[k][0], q = points[k][1];
                        if(p>=x && p<=a && q>=b && q<=y)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                    cnt++;
                }
                
                
            }
        }
        return cnt;
    }
};