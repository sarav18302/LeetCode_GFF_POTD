class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i =0,j =n-1;
        int ans =0;
        int h = 0;
        while(i<j)
        {
            h = min(height[i],height[j]);
            ans = max(ans,(j-i)*h);
            while(height[i]<=h && i<j ) i++;
            while(height[j]<=h && i<j ) j--;
        }
        return ans;
    }
};