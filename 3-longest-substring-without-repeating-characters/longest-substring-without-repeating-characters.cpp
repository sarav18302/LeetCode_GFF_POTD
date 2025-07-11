class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256,-1);
        int start = 0;
        int ans = 0;
        for(int i =0;i<s.size();i++)
        {
            if(mp[s[i]] >= start)
            {
                start = mp[s[i]]+1;
            }
            mp[s[i]] = i;
            ans = max(ans, i-start+1);
        }
        return ans;
    }
};