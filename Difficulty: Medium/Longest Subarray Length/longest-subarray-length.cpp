class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ans = 0;
        vector<int> nge(n,n);
        stack<int>st;
        for(int i =n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
            {
                st.pop();
                
                
            }
            if(!st.empty())
                nge[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        vector<int>pge(n,-1);
        for(int i =0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
            {
                st.pop();
                
                
            }
            if(!st.empty())
                pge[i] = st.top();
            st.push(i);
        }
        
        for(int i =0;i<n;i++)
        {
            int len = nge[i] - pge[i]-1;
            // cout<<nge[i]<<" "<<pge[i]<<endl;
            if(len>=arr[i])
            ans = max(ans,len);
        }
        return ans;
        
    }
};
