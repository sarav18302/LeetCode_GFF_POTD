// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {


        // Write your code here
        int t = N;
        vector<bool>factors(t+1,true);
        vector<int> ans;
        for(int i =2;i<=sqrt(t);i++)
        {
            if(N%i ==0 && factors[i])
            {
                while(N%i==0)
                {
                    ans.push_back(i);
                    N= N/i;
                }
            }
            else
            factors[i] = false;
        }
        
        if(N!=1) ans.push_back(N);
        return ans;
    }
};