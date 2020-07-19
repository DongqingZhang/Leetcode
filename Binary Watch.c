class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<vector<int>> combs;
        vector<string> res;
        vector<int> tmp;
        generateAllComb(1, combs, tmp, num);
        for(int i=0;i<combs.size();i++){
            int hour = 0;
            int minute = 0;
            for(int j=0;j<num;j++){
                if(combs[i][j]<=4){
                    hour+=pow(2,4-combs[i][j]);
                }
                if(combs[i][j]>4){
                    minute+=pow(2,10-combs[i][j]);
                }
            }
            if(hour>11||minute>59) continue;
            string tmp;
            tmp+=(to_string(hour)+':');
            if(minute<10) tmp+='0';
            tmp+=to_string(minute);
            res.push_back(tmp);
        }
        return res;
    }
    void generateAllComb(int start, vector<vector<int>>& res, vector<int>& tmp, int num){
        if(tmp.size()==num){
            res.push_back(tmp);
            return;
        }
        for(int i = start;i<=10-(num-1-tmp.size());i++){
            tmp.push_back(i);
            generateAllComb(i+1, res, tmp, num);
            tmp.pop_back();
        }
    }
};