class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        string s1 = words[0];
        ans.push_back(s1);
        for(int i =1;i<words.size();i++)
        {
            string s2 = words[i];
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            if(s1!=s2)
            {
                ans.push_back(words[i]);
                s1 = words[i];
            }
            
        }
        return ans;
    }
};