class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a = 0, b= 0;
        int n = nums1.size(), m = nums2.size();
        int mid = (m+n)/2;
        cout<<mid<<endl;
        int last = -1,prev = -1;
        while(a<n && b<m && mid >=0)
        {
            cout<<nums1[a] <<" "<<nums2[b]<<endl;
            if(nums1[a] < nums2[b])
            {
                prev = last;
                last = nums1[a];
                a++;
            }
            else
            {
                prev = last;
                last = nums2[b];
                b++;
            }
            mid--;
        }
        while(mid>=0 && a<n) 
        {
            cout<<nums1[a]<<endl;
            prev = last;
            last = nums1[a];
            a++;
            mid --;
        }
        while(mid>=0 && b<m) 
        {
            cout<<nums2[b]<<endl;
            prev = last;
            last = nums2[b];
            b++;
            mid --;
        }
        cout<<mid<<" "<<a<<" "<<b<<endl;
        cout<<last<<" "<<prev<<endl;
        if((m+n)%2)
        return last;
        else
        return (double) ((last+prev)/2.0);

    }
};