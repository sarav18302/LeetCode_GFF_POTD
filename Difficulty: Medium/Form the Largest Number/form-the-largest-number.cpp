class Solution {
  public:
    static bool compare(string&a , string&b)
    {
        return a+b > b+a;
    }
    string findLargest(vector<int> &arr) {
        // code here
        vector<string> temp;
        for(auto x:arr)
        temp.push_back(to_string(x));
        sort(temp.begin(),temp.end(),compare);
        string ans = "";
        for(auto x: temp)
        ans+=x;
        if(ans[0] == '0') return "0";
        return ans;
    }
};