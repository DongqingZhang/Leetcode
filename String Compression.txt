class Solution {
public:
    int compress(vector<char>& chars) {
        int a = 0, b = 0;
        while(b<chars.size()){
            while(b<chars.size() && chars[a] == chars[b]) b++;
            int rep = b-a;
            if(rep>1){
                string reps = to_string(rep);
                for(int i = a+1;i<=a+reps.length();i++) chars[i] = reps[i-a-1];
                for(int i = a+reps.length()+1;i<b;i++) chars[i] = 0;
            }
            a = b;
        }
        int s = 0, e = 0;
        while(e<chars.size()){
            while(e<chars.size() && chars[e] == 0) e++;
            if(e<chars.size())chars[s++]=chars[e++];
        }
        return s;
    }
};