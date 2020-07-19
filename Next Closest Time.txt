class Solution {
public:
    string nextClosestTime(string time) {
        unordered_set<int> set;
        vector<int> times(2,0);
        string res;
        times[0] = stoi(time.substr(0,2));
        times[1] = stoi(time.substr(3,2));
        
        set.insert(stoi(time.substr(0,1)));
        set.insert(stoi(time.substr(1,1)));
        set.insert(stoi(time.substr(3,1)));
        set.insert(stoi(time.substr(4,1)));
        while(true){
            nextTime(times);
            if(set.find(times[0]/10)!=set.end() && set.find(times[0]%10)!=set.end() && set.find(times[1]/10)!=set.end() && set.find(times[1]%10)!=set.end()){
                if(times[0]<10) res.push_back('0');
                res.append(to_string(times[0]));
                res.push_back(':');
                if(times[1]<10) res.push_back('0');
                res.append(to_string(times[1]));
                return res;
            }
        }
        return res;
    }
    void nextTime(vector<int>& time){
        if(time[1] == 59){
            time[0] = (time[0]+1)%24;
            time[1] = 0;
            return;
        }
        time[1]++;
    }
};