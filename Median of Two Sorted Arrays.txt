class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m+n;
        if (total%2) return helper(nums1, 0, m, nums2, 0, n, total/2+1);
        else return (helper(nums1, 0, m, nums2, 0, n, total/2) + helper(nums1, 0, m, nums2, 0, n, total/2+1))/2;
    }
    double helper(vector<int>& nums1, int pa, int m, vector<int>& nums2, int pb, int n, int k){
        if (m - pa > n - pb) return helper(nums2, pb, n, nums1, pa, m, k);
        if (m - pa == 0) return nums2[pb+k-1];
        if (k == 1) return min(nums1[pa],nums2[pb]);
        int ppa = min(k/2, m-pa);
        int ppb = k - ppa;
        if (nums1[pa+ppa-1]>nums2[pb+ppb-1]) return helper(nums1, pa, m, nums2, pb+ppb, n, k-ppb);
        else if (nums1[pa+ppa-1]<nums2[pb+ppb-1]) return helper(nums1, pa+ppa, m, nums2, pb, n, k-ppa);
        else return nums1[pa+ppa-1];
    }
};