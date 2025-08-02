class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        for(int i =0;i<n;i++)
        {
            map<char,int>mp;
            for(int j =i;j<n;j++)
            {
                mp[s[j]]++;
                int leastF = INT_MAX;
                int mostF = INT_MIN;
                for(auto it:mp)
                {
                    leastF = min(leastF,it.second);
                    mostF = max(mostF,it.second);
                }
                ans+=(mostF-leastF);
            }
            
        }
        return ans;
    }
};