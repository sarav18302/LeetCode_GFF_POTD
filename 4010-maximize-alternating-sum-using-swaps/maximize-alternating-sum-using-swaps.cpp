class Solution {
public:
    vector<long long> parent,size;
    long long findPar(int x)
    {
        if(x == parent[x])
            return x;
        return parent[x] = findPar(parent[x]);
    }
    void union_by_size(long long x,long long y)
    {
        int parx = findPar(x);
        int pary = findPar(y);
        if(parx == pary) return ;
        if(size[parx]<size[pary])
        {
            parent[parx] = pary;
            size[pary]+=size[parx];
        }
        else
        {
            parent[pary] = parx;
            size[parx]+=size[pary];
        }
    }
    
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
        if(swaps.size()==0)
        {
            long long ans = 0;
            for(int i=0;i<n;i++ )
                {
                    if(i%2==0)
                        ans+=nums[i];
                    else
                        ans-=nums[i];
                }
            return ans;
        }
        
        parent.resize(n);
        size.resize(n,1);
        for(int i =0;i<n;i++)
            parent[i] = i;
        for(auto x: swaps)
        {
            union_by_size(x[0],x[1]);
        }
        map<long long,vector<long long>>connect;
        for(int i =0;i<n;i++)
            connect[findPar(i)].push_back(i);
        vector<long long>eve,odd;
        long long ans = 0LL;
        for(auto [k,v]: connect)
            {
                vector<int> vals;
                long long evecnt = 0;
                for(auto x: v)
                    {
                        if(x%2 ==0)
                            evecnt++;
                        vals.push_back(nums[x]);
                    }
                sort(vals.begin(),vals.end(),greater<int>());
                for(int i =0;i<evecnt;i++)
                    ans+=vals[i];
                for(int i = evecnt;i<vals.size();i++)
                    ans-=vals[i];
                
            }
        
        return ans;
    }
};