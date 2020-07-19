class Solution {
public:
    static bool myComp(string a, string b){
        return (a+b>b+a);
    }
    string largestNumber(vector<int>& nums) {
        string res;
        vector<string> arr;
        int len = nums.size();
        for(int i=0;i<len;i++) arr.push_back(to_string(nums[i]));
        sort(arr.begin(),arr.end(),myComp);
        for(auto a:arr) res.append(a);
        while(res[0]=='0'&&res.size()>1) res.erase(res.begin());
        return res;
    }

};