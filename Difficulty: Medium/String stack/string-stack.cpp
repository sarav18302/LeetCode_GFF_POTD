class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        // code here
        int m = pat.size(), n = tar.size();
        int i = m-1, j = n-1;
        while(i>=0 && j>=0)
        {
            if(pat[i] == tar[j])
            {
                i--;
                j--;
            }
            else
            {
                i-=2;
            }
            // cout<<i<<" "<<j<<endl;
            if(j == -1)
            return true;
        }
        return false;
    }
};