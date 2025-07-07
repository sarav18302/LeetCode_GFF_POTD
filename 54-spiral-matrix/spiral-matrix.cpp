class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int left =0,right = n-1,top =0, bottom = m-1;
        int d = 1;
        vector<int> ans;
        while(top<=bottom && left <=right)
        {
            if(d == 1)
            {
                for(int i = left;i<=right;i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                d = 2;
                top++;
            }
            else if(d ==2)
            {
                for(int i = top;i<=bottom;i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                d = 3;
                right--;
            }
            else if(d == 3)
            {
                for(int i = right;i>=left;i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                d =4;
                bottom--;
            }
            else if(d ==4)
            {
                for(int i = bottom;i>=top;i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                d = 1;
                left++;
            }
        }
        return ans;
    }
};