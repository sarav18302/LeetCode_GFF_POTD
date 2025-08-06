class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        set<int>s;
        s.insert(1);
        s.insert(n);
        for(int i =2;i<=sqrt(n);i++)
        {
            if(n%i ==0)
            {
                s.insert(i);
                s.insert(n/i);
            }
        }
     for(auto x: s)
     cout<<x<<" ";
    }
};