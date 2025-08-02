class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp;
        int n = s.size();
        if(n!=t.size())
        return false;
        for(int i =0;i<n;i++)
        {
            mp[s[i]]++;
        }
        for(int i =0;i<n;i++)
        {
            mp[t[i]] --;
            if(mp[t[i]]<0)
            return false;
        }
        for(int i =0;i<n;i++)
        {
            if(mp[s[i]]!=0)
            return false;
        }
        return true;
    }
};