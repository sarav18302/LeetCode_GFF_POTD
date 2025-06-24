class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
     int n = s.size();
     string t = "";
     vector <string> ans;
     for(int i =0;i<n;i++)
     {
        t+=s[i];
        if(t.size() == k)
        {
            ans.push_back(t);
            t = "";
        }
     }
     if(t.size()!=0)
     {
        // cout<<t.size();
        for(int i =t.size()+1;i<=k;i++)
        {
            t+=fill;
        }
        ans.push_back(t);
     }   
     return ans;
    }
};