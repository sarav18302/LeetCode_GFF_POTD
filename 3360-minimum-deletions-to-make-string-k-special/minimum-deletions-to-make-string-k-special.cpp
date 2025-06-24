class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<char,int>mp;
        int n = word.size();
        for(int i =0;i<n;i++)
        {
            mp[word[i]]++;
        }
        vector<int>fre;
        for(auto x: mp)
        {
            fre.push_back(x.second);
            // cout<<x.second<<" ";
        }
        // cout<< endl;
        sort(fre.begin(),fre.end());
        int ans = INT_MAX;
        for(int i =0;i<fre.size();i++)
        {
            int b = fre[i];
            int cnt = 0;
            for(int j =0;j<fre.size();j++)
            {
                if(fre[j] < b) cnt+=fre[j];
                else if(fre[j] > b+k) cnt += (fre[j]-b-k);
            }
            // cout<<cnt<<" ";
            ans = min(ans,cnt);
        }
        return ans;
    }
};