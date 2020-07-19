class Solution {
public:
    vector<bool> used;
    unordered_map<int, bool> map;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        for(int i = 0;i<=maxChoosableInteger;i++) used.push_back(false);
        if(desiredTotal<=0) return true;
        if(desiredTotal>maxChoosableInteger*(maxChoosableInteger+1)/2) return false;
        return helper(desiredTotal);
    }
    bool helper(int desiredTotal){
        if(desiredTotal <= 0) return false;
        int key = format(used);
        if(map.find(key) == map.end()){
            for(int i = 1;i<used.size();i++){
                if(!used[i]){
                    used[i] = true;
                    if(!helper(desiredTotal - i)){
                        used[i] = false;
                        return true;
                    }
                    used[i] = false;
                }
            }
            map[key] =false;
        }
        return map[key];
    }
    int format(vector<bool> used){
        int val = 0;
        for(auto a:used){
            val<<=1;
            val |= a;
        }
        return val;
    }
};