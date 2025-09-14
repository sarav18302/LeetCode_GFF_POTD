class Solution {
public:
    string lcase(string s)
    {
        for(char&c:s)
        c = tolower(c);
        return s;
    }
    string vmask(string s)
    {
        for(char&c:s)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '*';
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<string> words(wordlist.begin(),wordlist.end());
        map<string,string>lower, mask;
        int n = wordlist.size();
        for(int i =n-1;i>=0;i--)
        {
            string word = wordlist[i];
            string wlow = lcase(word);
            lower[wlow] = word;
            mask[vmask(wlow)] = word;
        }
        vector<string> ans;
        for(int i =0;i<queries.size();i++)
        {
            string query = queries[i];
            string qlow = lcase(query);
            string qvmask = vmask(qlow); 
            if(words.count(query))
            {
                ans.push_back(query);
            }
            else if(lower.count(qlow))
            {
                ans.push_back(lower[qlow]);
            }
            else if(mask.count(qvmask))
            {
                ans.push_back(mask[qvmask]);
            }
            else
            ans.push_back("");

        }
        return ans;
    }
};