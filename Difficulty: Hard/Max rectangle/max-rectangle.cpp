class Solution {
  public:
    int findHistogramArea(vector<int> &height)
    {
        stack<int>st;
        int area = 0;
        int n = height.size();
        for(int i =0;i<=n;i++)
        {
            while(!st.empty()&& (i==n || height[st.top()]>=height[i]))
            {
                
                int h = height[st.top()];
                int w= 0;
                st.pop();
                if(!st.empty())
                w = i-st.top()-1;
                else
                w = i;
                area = max(area,h*w);
            }
            st.push(i);
        }
        return area;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int m = mat.size(), n = mat[0].size();
        int ans = 0;
        vector<int> height(n,0);
        for(int i =0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(mat[i][j] == 0)
                height[j] = 0;
                else
                height[j]++;
            }
            int area = findHistogramArea(height);
            ans = max(area,ans);
        }
        return ans;
    }
};