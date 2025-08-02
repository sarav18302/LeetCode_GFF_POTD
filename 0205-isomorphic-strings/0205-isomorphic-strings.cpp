class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        map<char,int>mp1,mp2;
        for(int i =0;i<n;i++)
        {
            if(mp1.find(s[i])!=mp1.end() || mp2.find(t[i])!=mp2.end())
            {
                // cout<<"Here "<<s[i]<<" "<<t[i]<<endl;
                if(mp1[s[i]]!= mp2[t[i]] )
                return false;
            }
            else
            {
                mp1[s[i]] = i+1;
                mp2[t[i]] = i+1;
            }
            cout<<s[i]<<" "<<mp1[s[i]]<<endl;
        }
        return true;
    }
};