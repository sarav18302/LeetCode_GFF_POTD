class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        vector<long long>f(n,0LL);
        for(auto x: mana)
        {
            long long now = f[0];
            for(int i =1;i<n;i++)
            {
                now = max(now+1LL*skill[i-1]*x,f[i]);
            }
            f[n-1] = now+skill[n-1]*x;
            for(int i = n-2;i>=0;i-- )
            {
                f[i] = f[i+1] - 1LL*skill[i+1]*x;
            }
        }
        return f[n-1];
    }
};