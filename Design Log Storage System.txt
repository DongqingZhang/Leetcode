class LogSystem {
public:
    vector<pair<string, int>> logs;
    LogSystem() {
    }
    void put(int id, string timestamp) {
        logs.push_back({timestamp, id});
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        int len = 0;
        if(gra.compare("Year") == 0) len = 4;
        if(gra.compare("Month") == 0) len = 7;
        if(gra.compare("Day") == 0) len = 10;
        if(gra.compare("Hour") == 0) len = 13;
        if(gra.compare("Minute") == 0) len = 16;
        if(gra.compare("Second") == 0) len = 19;
        vector<int> res;
        for(auto a:logs){
            if(a.first.substr(0,len)>=s.substr(0,len) && a.first.substr(0,len)<=e.substr(0,len)) res.push_back(a.second);
        }
        return res;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */