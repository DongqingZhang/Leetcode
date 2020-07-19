class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> map;
        for(auto a:paths){
            istringstream buf(a);
            istream_iterator<string> begin(buf), end;
            vector<string> files(begin, end);
            string dir = files[0];
            for(int i = 1;i < files.size();i++){
                size_t pos= files[i].find('(');
                string tmp1 = files[i].substr(0,pos);
                string tmp2 = files[i].substr(pos+1);
                map[tmp2.substr(0,tmp2.length()-1)].push_back(dir+"/"+tmp1);
            }
        }
        vector<vector<string>> res;
        for(auto a:map){
            if(a.second.size()>1) res.push_back(a.second);
        }
        return res;
    }
};