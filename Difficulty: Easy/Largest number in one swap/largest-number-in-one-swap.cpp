class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.size();
        char maxDigit = '0';
        int l = -1, r = -1, idx = -1;
        for(int i = n-1;i>=0;i--)
        {
            if(s[i]> maxDigit)
            {
                maxDigit = s[i];
                idx = i;
            }
            else if(s[i]<maxDigit)
            {
                l = i;
                r = idx;
            }
        }
        
        if(l == -1) return s;
        swap(s[l],s[r]);
        return s;
    }
};