class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int left = (n1+n2+1)/2;
        int l = 0, r = n1;
        int n = n1+n2;
        while(l<=r)
        {
            cout<<l<<" "<<r<<" ";
            int mid1 = (l+r)/2;
            int mid2 = left - mid1;
            cout<<mid1<<" "<<mid2<<endl;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1-1>=0)
            l1 = nums1[mid1-1];
            if(mid2-1>=0)
            l2 = nums2[mid2-1];
            if(mid1<n1)
            r1 = nums1[mid1];
            if(mid2<n2)
            r2 = nums2[mid2];
            if(l1<=r2 && l2<=r1)
            {
                if(n%2==0)
                return (double)((max(l1,l2)+ min(r1,r2))/2.0);
                else
                return max(l1,l2);
            }
            else if(l1>r2)
            r = mid1-1;
            else
            l = mid1+1;


        }
        return 0;
    }
};