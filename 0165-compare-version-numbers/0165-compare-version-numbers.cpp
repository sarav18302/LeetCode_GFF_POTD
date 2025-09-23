class Solution {
public:
    vector<int> split(string s)
    {
        string t = "";
        vector<int> ans;
        for(auto x: s)
        {
            if(x== '.')
            {
                ans.push_back(stoi(t));
                t = "";
                continue;
            }
            t+=x;
        }
        if(t!="")
        ans.push_back(stoi(t));
        return ans;
    }
    vector<int> addzeroes(vector<int> s,int cnt)
    {
        while(cnt--)
        {
            s.push_back(0);
        }
        return s;
    }
    int compareVersion(string version1, string version2) {
        auto v1 = split(version1);
        auto v2 = split(version2);
        if(v1.size()>v2.size())
        v2 = addzeroes(v2,(v1.size()-v2.size()));
        else if(v1.size()<v2.size())
        v1 = addzeroes(v1,(-v1.size()+v2.size()));

        // for(auto x: v1)
        // cout<<x<<" ";
        // cout<<endl;
        // for(auto x: v2)
        // cout<<x<<" ";
        // cout<<endl;

        for(int i =0;i<v1.size();i++)
        {
            if(v1[i]<v2[i])
            return -1;
            if(v1[i]>v2[i])
            return 1;
        }
        return 0;
    }
};