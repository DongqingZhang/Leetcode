class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<bool> dicts(26,false);
        for(auto a:letters) dicts[a-'a']=true;
        while(true){
            target++;
            if(target > 'z') target = 'a';
            if(dicts[target-'a']) return target;
        }
        return target;
    }
};