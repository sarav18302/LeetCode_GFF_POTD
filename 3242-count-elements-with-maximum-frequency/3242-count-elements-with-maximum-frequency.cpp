class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        int maxval = 0;
        for(auto x: nums)
        {
            mp[x]++;
            maxval = max(maxval,mp[x]);
        }
        int ans = 0;
        for(auto [k,v]:mp)
        {
            if(v == maxval)
            ans+=(maxval);
        }
        return ans;
    }
};