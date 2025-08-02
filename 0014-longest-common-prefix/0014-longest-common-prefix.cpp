class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       int m = strs.size(),n = strs[0].size();
       string ans = "";
       bool flag = false;
       for(int i = 0;i<n;i++)
       {
            char ref = strs[0][i];
            // cout<<ref<<endl;
            for(int j = 1;j<m;j++)
            {
                // cout<<j<<endl;
                if(i>=strs[j].size() || strs[j][i] != ref)
                {
                    flag = true;
                    break;
                }
                cout<< strs[j][i]<<endl;
            }
            // cout<<flag<<endl;
            if(flag)
            break;
            ans+=ref;
            // cout<<ans<<endl;
       }
       return ans;
    }
};