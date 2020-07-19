class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int a = 0;
        int b = nums.size();
        while(b-a > 1){
            if (target>nums[(a+b)/2])
                a = (a+b)/2;
            else if(target<nums[(a+b)/2])
                b = (a+b)/2;
            else return (a+b)/2;
        }
        if (target>nums[(a+b)/2])
            return (a+b)/2+1;
        else return (a+b)/2;
    }
};