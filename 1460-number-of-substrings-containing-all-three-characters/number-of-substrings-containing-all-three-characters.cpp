class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        map<char,int>mp;
        int start = 0,cnt = 0;;
        for(int i =0;i<n;i++)
        {
            mp[s[i]]++;
            // cout<<s.substr(start,i-start+1)<<" "<<mp['a']<<endl;
            if(mp['a'] && mp['b'] && mp['c'])
            {
                // cout<<s.substr(start,i-start+1)<<endl;
                
                while(start <i && mp['a'] && mp['b'] && mp['c'])
                {
                    
                    mp[s[start]]--;
                    start++;
                    cnt +=(n-i);
                }
                // cout<<s.substr(start,i-start+1)<<endl;
            }
        }
        return cnt;
    }
};