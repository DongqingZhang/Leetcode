class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.length()<k) return 0;
        unordered_map<char,int> mySet;
        for(int i=0;i<s.length();i++){
            mySet[s[i]]++;
        }
        int minF = INT_MAX;
        char t = s[0];
        for(auto a:mySet){
            if(minF>a.second){
                t = a.first;
                minF = a.second;
            }
        }
        if(minF>=k) return s.length();
        int point = 0;
        for(int i=0;i<s.length();i++) if(s[i]==t){point = i;break;}
        cout<<point<<endl;
        cout<<s.substr(0,point)<<endl;
        int ind = min(point+1,(int)s.length()-1);
        return max(longestSubstring(s.substr(0,point), k),longestSubstring(s.substr(ind,s.length()-ind), k));
    }
    
};