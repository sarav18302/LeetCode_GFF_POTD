class Solution {
public:
    bool check(char x)
    {
        if(x == 'a'|| x=='e'|| x == 'i' || x == 'o' || x == 'u'|| x == 'A' || x == 'E' || x =='I'|| x == 'O'|| x == 'U')
        return true;
        return false;
    }
    int maxFreqSum(string s) {
        map<char,int>mp;
        int freqv = 0, freqc = 0;
        for(auto x: s)
        {
            if(check(x))
            {
                mp[x]++;
                freqv = max(freqv,mp[x]);
            }
            else
            {
                mp[x]++;
                freqc = max(freqc,mp[x]); 
            }
        }
        return freqv+freqc;
    }
};