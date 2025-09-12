class Solution {
public:
    bool check(char x)
    {
        if(x == 'a'|| x=='e'|| x == 'i' || x == 'o' || x == 'u'|| x == 'A' || x == 'E' || x =='I'|| x == 'O'|| x == 'U')
        return true;
        return false;
    }
    bool doesAliceWin(string s) {
        int n = s.size();
        int  r = 0, turn = 0;
        int vowelcnt = 0;
        for(auto x: s)
        {
            if(check(x))
            vowelcnt++;
        }
        if(vowelcnt >0)
        return true;
        return false;
    }
};