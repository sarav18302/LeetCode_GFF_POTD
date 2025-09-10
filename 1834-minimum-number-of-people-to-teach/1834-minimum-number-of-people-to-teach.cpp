class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> need;
        for(auto p: friendships)
        {
            auto x = p[0]-1, y = p[1] -1;
            bool ok = false;
            for(auto l:languages[x])
            {
                for(auto r: languages[y])
                {
                    if(l==r)
                    {
                        ok = true;
                        break;
                    }
                }
                
            }
            if(!ok)
                {
                    need.insert(x);
                    need.insert(y);
                }
        }

        int ans = languages.size()+1;
        for(int i =1;i<=n;i++)
        {
            int cnt = 0;
            for(auto v: need)
            {
                bool found = false;
                for(auto c: languages[v])
                {
                    if(c==i){
                        found = true;
                        break;
                    }
                }
                if(!found)
                {
                    cnt++;
                }
            }
            ans = min(ans,cnt);
        }
        return ans;
    }
};