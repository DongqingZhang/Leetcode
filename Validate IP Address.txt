class Solution {
public:
    string validIPAddress(string IP) {
        if(isIPv4(IP)) return "IPv4";
        if(isIPv6(IP)) return "IPv6";
        return "Neither";
    }
    bool isIPv4(string IP){
        vector<string> res = mysplit(IP,'.');
        if(res.size()!=4) return false;
        for(auto a:res){
            if(!isNum(a)) return false;
        }
        return true;
    }
    bool isIPv6(string IP){
        vector<string> res = mysplit(IP,':');
        if(res.size()!=8) return false;
        for(auto a:res){
            if(!isNumv6(a)) return false;
        }
        return true;
    }
    bool isNum(string s){
        if(s.length()>3 || s.length() == 0) return false;
        for(auto a:s){if(a<'0' || a>'9') return false;}
        if(stoi(s) > 255) return false;
        if(stoi(s) == 0 && s.length()>1) return false;
        if(stoi(s)!=0 && s[0] == '0') return false;
        return true;
    }
    bool isNumv6(string s){
        if(s.length() > 4 || s.length() == 0) return false;
        for(auto a:s){
            if(!((a>='0'&&a<='9')||(a>='a'&&a<='f')||(a>='A'&&a<='F'))) return false;
        }
        return true;
    }
    vector<string> mysplit(string s, char d){
        vector<string> res;
        res.push_back("");
        int cnt = 0;
        for(auto a:s){
            if(a == d){
                res.push_back("");
                cnt++;
            }
            else res[cnt].push_back(a);
        }
        return res;
    }
};