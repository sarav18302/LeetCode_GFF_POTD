class Solution {
public:
    int gcd(int a, int b)
    {
        if(b>a)
        return gcd(b,a);
        if(b == 0)
        return a;
        return gcd(b,a%b);
    }
    bool check(int a, int b)
    {
        if(a<b)
        return check(b,a);
        if(gcd(a,b) == 1)
        return false;
        return true;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        st.push(nums[0]);
        for(int i =1;i<n;i++)
        {
            while(!st.empty() && check(nums[i] , st.top()))
            {
                int ele = st.top();
                st.pop();
                int hcf = gcd(ele,nums[i]); 
                // cout<<ele<<" "<<nums[i]<<endl;
                long long lcm = 1LL*nums[i]*ele/hcf;
                nums[i] = lcm; 
            }
            st.push(nums[i]);
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};