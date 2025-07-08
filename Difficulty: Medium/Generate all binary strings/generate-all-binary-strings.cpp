// User function Template for C++

class Solution {
  public:
   void helper(int num, vector<string>&ans, string t)
   {
       if(t.size() == num)
       {
           ans.push_back(t);
           return ;
       }
       helper(num,ans,t+'0');
       if(t.size() == 0 || t.back()!='1' )
       {
           helper(num,ans,t+'1');
       }
       
   }
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string> ans;
        helper(num,ans,"");
        return ans;
        
    }
};