class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int cnt = 0;
        int n = arr.size();
        for(int i =n-1;i>1;i--)
        {
            int low = 0, high = i-1;
            while(low< high)
            {
                if(arr[low]+arr[high] > arr[i])
                {
                    cnt+=(high-low);
                    high--;
                }
                else
                low++;
                
            }
        }
        return cnt;
    }
};
