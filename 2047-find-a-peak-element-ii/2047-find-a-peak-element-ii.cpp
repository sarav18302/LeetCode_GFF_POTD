class Solution {
public:
    int findMaxEle(vector<vector<int>>& mat,int idx)
    {
        int m = mat.size(), n= mat[0].size();
        int ind = 0, ans = mat[0][idx];
        for(int i =1;i<m;i++)
        {
            if(ans< mat[i][idx])
            {
                ans = mat[i][idx];
                ind = i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n= mat[0].size();
        int l = 0, r= n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int row = findMaxEle(mat,mid);
            int left = mid-1>=0 ? mat[row][mid-1]:-1;
            int right = mid+1<n? mat[row][mid+1]:-1;
            if(mat[row][mid] > left && mat[row][mid] > right)
            return {row,mid};
            else if(mat[row][mid] < left)
            r = mid-1;
            else
            l= mid+1;
        }
        return {0,0};
    }
};