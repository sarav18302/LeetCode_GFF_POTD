class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int begin = 0, end = 0;
        int maxcnt = 0, maxlen = 0;
        map<char,int>mp;
        while(end<n)
        {
            mp[s[end]]++;
            maxcnt = max(maxcnt,mp[s[end]]);
            while(end-begin+1-maxcnt >k && begin <=end)
            {
                mp[s[begin]]--;
                begin++;
                for(auto x: mp)
                {
                    if(x.second > maxcnt)
                    maxcnt = x.second;
                }
            }
            if(maxlen < end- begin+1)
                maxlen = end-begin+1;
            end++;

        }
        return maxlen;
    }
};