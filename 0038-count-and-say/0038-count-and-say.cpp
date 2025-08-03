class Solution {
public:
    string findRLE(string s)
    {
        string ans = "";
        int  cnt = 1;
        char ele = s[0];
        int n = s.size();
        for(int i =1;i<n;i++)
        {
            if(s[i] == ele)
            cnt+=1;
            else
            {
                ans+=to_string(cnt);
                ans+=ele;
                ele = s[i];
                cnt = 1;
            }
        }
        ans+=to_string(cnt);
        ans+=ele;
        return ans;
    }
    string countAndSay(int n) {
      string ans = "1";
      if(n==1)
      return "1";
      for(int i =1;i<n;i++)
      ans = findRLE(ans);
      return ans;  
    }
};