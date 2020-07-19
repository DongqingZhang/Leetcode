class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (!nums1.size()||!nums2.size())
            return;
        int indA, indB, indF;
        indA = m - 1;
        indB = n - 1;
        indF = m + n - 1;
        while (indA >= 0&&indB >= 0){
            if (nums1[indA] >= nums2[indB]) nums1[indF--] = nums1[indA--];
            else nums1[indF--] = nums2[indB--];
        }
        while(indB >= 0){
            nums1[indF--] = nums2[indB--];
        }
    }
};