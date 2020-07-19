class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s;
        for (int i=0;i<strs.size();i++){
            s+=to_string(strs[i].size())+"@"+strs[i];
        }
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while(i<s.length()){
            int start = i;
            while(s[i]!='@') i++;
            i++;
            int len = stoi(s.substr(start,i-start-1));
            res.push_back(s.substr(i,len));
            i+=len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));