#include<cmath>
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int maxArea = 0;
        int maxDiag = -1; // store squared diagonal

        for (int i = 0; i < n; i++) {
            int h = dimensions[i][0];
            int w = dimensions[i][1];
            int diagSq = h * h + w * w;  // squared diagonal
            int area = h * w;

            // Compare diagonals first, then area if tie
            if (diagSq > maxDiag || (diagSq == maxDiag && area > maxArea)) {
                maxDiag = diagSq;
                maxArea = area;
            }
        }
        return maxArea;
    }
};