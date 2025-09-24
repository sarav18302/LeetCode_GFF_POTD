class Solution {
public:
    string fractionToDecimal(int64_t n, int64_t d) {
        if(n ==0) return "0";
        string ans="";
        if(n<0 ^ d<0) ans+="-";
        n = abs(n);
        d = abs(d);
        ans+=to_string(n/d);
        if(n%d == 0) return ans; 
        ans+=".";
        map<int,int>mp;
        for(int64_t r = n%d;r;r%=d)
        {
            if(mp.count(r)>0)
            {
                ans.insert(mp[r],1,'(');
                ans+=')';
                break;
            }
            mp[r] = ans.size();
            r*=10;
            ans+=to_string(r/d);
        }
        return ans;
        
    }
};