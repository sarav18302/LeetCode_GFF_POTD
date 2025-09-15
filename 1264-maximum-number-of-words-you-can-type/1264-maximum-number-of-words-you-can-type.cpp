class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char>s;
        for(auto x: brokenLetters)
        {
            s.insert(x);
        }
        vector<string> arr;
        string t = "";
        for(auto x: text)
        {
            if(x== ' ')
            {
                arr.push_back(t);
                t = "";
                continue;
            }
            t+=x;
        }
        arr.push_back(t);
        int cnt = 0;
        for(auto row: arr)
        {
            bool flag = true;
            // cout<<row<<endl;
            for(auto x: row)
            {
                if(s.count(x))
                {
                    flag = false;;
                    break;
                }
            }
            if(flag)
            cnt++;
        }
        return cnt;
    }
};