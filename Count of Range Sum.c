class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sum;
        sum.push_back(0);
        for (int i = 0;i<nums.size();i++)
            sum.push_back(sum[sum.size()-1]+nums[i]);
        return sortNcount(sum, 0, sum.size()-1, lower, upper);
    }
    int sortNcount(vector<long>& nums, int l, int r, int lower, int upper){
        if (l >= r) return 0;
        int mid = (l+r)/2;
        int count = sortNcount(nums, l, mid, lower, upper) + sortNcount(nums, mid+1, r, lower, upper);
        int low = mid+1, high = mid+1;
        for (int i = l;i <= mid;i++){
            while (low <= r && nums[low] - nums[i] < lower) low++;
            while (high <= r && nums[high] - nums[i] <= upper){
                high++;
            }
            count += (high - low);
        }
        myMerge(nums, l, r, mid);
        return count;
    }
    void myMerge(vector<long>& nums, int l, int r, int mid){
        vector<int> c;
        int i = l, j = mid+1;
        while (i <= mid && j <= r){
            if (nums[i] < nums[j]){
                c.push_back(nums[i]);
                i++;
            }
            if (nums[i]>=nums[j]){
                c.push_back(nums[j]);
                j++;
            }
        }
        if (i > mid)
            while(j<=r){
                c.push_back(nums[j]);
                j++;
            }
        if (j > r)
            while(i <= mid){
                c.push_back(nums[i]);
                i++;
            }
        for (int i = l;i<=r;i++){
            nums[i] = c[i - l];
        }
    }
};