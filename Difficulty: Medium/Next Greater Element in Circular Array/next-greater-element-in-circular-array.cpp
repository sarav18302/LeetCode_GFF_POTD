class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        stack<int>st;
        int n = arr.size();
        vector<int>ans(n,-1);
        for(int i =2*n-1;i>=0;i--)
        {
            int idx = i%n;
            while(!st.empty() && arr[st.top()]<=arr[idx] )
            {
                st.pop();
            }
            if(!st.empty())
            ans[idx] = arr[st.top()];
            st.push(idx);
        }
        while(!st.empty())
        st.pop();
        
        return ans;
    }
};

// 5 6 4 3 2 1
// 6-1-1-1-1-1
//-1-1 5 5 5 5
// 6-1 5 5 5 5