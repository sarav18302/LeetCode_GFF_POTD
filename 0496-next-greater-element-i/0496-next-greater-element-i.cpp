class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int>st;
        vector<int>ans(n,-1);
        map<int,int>mp;
        for(int i =0;i<n;i++)
        mp[nums2[i]] = i;
        for(int i = n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i%n])
            st.pop();
            if(i<n)
            {
                if(!st.empty())
                ans[i] = st.top();
            }
            st.push(nums2[i%n]);
        }
        for(auto x: ans)
        cout<<x<<" ";
        vector<int>res;
        for(int i =0;i<nums1.size();i++)
        {
            res.push_back(ans[mp[nums1[i]]]);
        }
        return res;
    }
};