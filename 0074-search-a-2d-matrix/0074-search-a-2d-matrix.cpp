class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l1 = 0, r1= m-1;
        int idx = -1;
        while(l1<=r1)
        {
            int mid = (l1+r1)/2;
            if(matrix[mid][0] == target)
            return true;
            else if(matrix[mid][0] < target)
            {
                l1 = mid+1;
                idx = mid;
            }
            else
            r1 = mid-1;
        }
        if(idx == -1)
        return false;
        int l = 0, r = n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(matrix[idx][mid] == target)
            return true;
            else if(matrix[idx][mid] < target)
            l = mid+1;
            else
            r = mid-1;
        }
        return false;
    }
};