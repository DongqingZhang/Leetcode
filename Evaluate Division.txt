class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, vector<string>> pairs;
        unordered_map<string, vector<double>> valuePairs;
        for(int i = 0;i<equations.size();i++){
            pairs[equations[i].first].push_back(equations[i].second);
            pairs[equations[i].second].push_back(equations[i].first);
            valuePairs[equations[i].first].push_back(values[i]);
            valuePairs[equations[i].second].push_back(1.0/values[i]);
        }
        vector<double> res;
        for(auto a:queries){
            string start = a.first;
            string end = a.second;
            double value = 1.0;
            unordered_set<string> set;
            double tmp = dfs(start, end, pairs, valuePairs, value, set);
            res.push_back(tmp);
        }
        return res;
    }
    double dfs(string start, string end, unordered_map<string, vector<string>>& pairs, unordered_map<string, vector<double>>& valuePairs, double value, unordered_set<string>& set){
        if(set.find(start) != set.end()) return -1.0;
        if(pairs.find(start) == pairs.end()) return -1.0;
        if(start == end) return value;
        vector<string> neighbors = pairs[start];
        vector<double> valueNei = valuePairs[start];
        set.insert(start);
        double tmp = 0.0;
        for(int i = 0;i < neighbors.size();i++){
            string startNew = neighbors[i];
            tmp = dfs(startNew, end, pairs, valuePairs, value*valueNei[i], set);
            if(tmp!=-1.0) break;
        }
        set.erase(start);
        return tmp;
    }
};