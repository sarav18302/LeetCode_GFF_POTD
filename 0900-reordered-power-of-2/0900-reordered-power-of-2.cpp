class Solution {
public:
    bool helper(int n,map<int,int> &mp, int t)
    {
        if(n==0)
        {
            cout<<t<<endl;
            if(t<=0)
            return false;
            if((t&(t-1)) ==0)
            return true;
            else
            return false;
        }
        bool val = false;
        for(auto & x: mp)
        {
            if(x.second <=0)
                continue;
            if(x.first == 0 && t==0)
            continue;
            t = t*10 + x.first;
            x.second--;
            val = val || helper(n-1,mp,t);
            t-=x.first;
            t = t/10;
            x.second++;
        }
        return val;
    }
    bool reorderedPowerOf2(int n) {
        int t = n;
        int cnt =0;
        map<int,int>mp;
        while(t>0)
        {
            cnt++;
            mp[t%10]++;
            t = t/10;
        }
        return helper(cnt,mp,0);
    }
};