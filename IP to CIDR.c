class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> res;
        long curip = split(ip);
        while(n){
            int trail0 = trailing0(curip);
            while(1<<trail0 > n) trail0--;
            n -= (1<<trail0);
            res.push_back(generate(curip, trail0));
            curip += (1<<trail0);
        }
        return res;
    }
    long split(string ip){
        int start = 0;
        long res, base = 16777216;
        for(int i=0;i<=ip.length();i++){
            if(ip[i]=='.' || i==ip.length()){
                res += stoi(ip.substr(start,i-start))*base;
                cout<<res<<endl;
                start = i+1;
                base/=256;
            }
        }
        cout<<res<<endl;
        return res;
    }
    int trailing0(long ip){
        if(ip == 0) return 32;
        int res = 0;
        while(ip){
            if(ip%2) return res;
            else{
                ip/=2;
                res++;
            }
        }
        return res;
    }
    string generate(long ip, int t){
        string res;
        res.append(to_string(ip/16777216));
        res.push_back('.');
        res.append(to_string((ip/65536)%256));
        res.push_back('.');
        res.append(to_string((ip/256)%256));
        res.push_back('.');
        res.append(to_string(ip%256));
        res.push_back('/');
        res.append(to_string(32-t));
        return res;
    }
};