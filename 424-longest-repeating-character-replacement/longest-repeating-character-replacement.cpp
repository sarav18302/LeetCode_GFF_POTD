class Solution {
public:
    int characterReplacement(string s, int k) {
        map<int,int>mp;
        int start = 0;
        int maxcnt = 0,ans = 0;
        int n = s.size();
        for(int i =0;i<n;i++)
        {
            mp[s[i]]++;
            maxcnt = max(maxcnt,mp[s[i]]);
            while(i-start+1 - maxcnt  > k && start<=i)
            {
                mp[s[start]]--;
                start++;
                for(auto &x: mp)
                {
                    maxcnt = max(maxcnt, x.second);
                }
            }
            ans = max(ans, i-start+1);
        }
        return ans;
    }
};