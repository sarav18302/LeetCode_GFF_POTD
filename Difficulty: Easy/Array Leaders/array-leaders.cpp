

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> greater(n+1,-1e9);
        for(int i = n-1;i>=0;i--)
        {
            greater[i] = max(greater[i+1],arr[i]);
        }
        vector<int>ans;
        for(int i =0;i<n;i++)
        {
            if(arr[i] >= greater[i])
            ans.push_back(arr[i]);
        }
        return ans;
    }
};