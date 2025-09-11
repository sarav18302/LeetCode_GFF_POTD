class Solution {
public:
    bool check(char x)
    {
        if(x == 'a'|| x=='e'|| x == 'i' || x == 'o' || x == 'u'|| x == 'A' || x == 'E' || x =='I'|| x == 'O'|| x == 'U')
        return true;
        return false;
    }
    string sortVowels(string s) {
        int freq[128];
        int n = s.size();
        for(int i =0;i<n;i++)
        {
            if(check(s[i]))
            freq[(int)s[i]]++;
        }
        int idx = 0;
        for(int i =0;i<n;i++)
        {
            if(check(s[i]))
            {
                while(freq[idx]==0)idx++;
                s[i] = (char)idx;
                freq[idx]--;
            }
        }
        return s;
    }
};