class Solution {
public:
    void reverseWords(string &s) {
        int start = 0, end = 0, len = s.length();
        while(1){
            while(end<len&&s[end++]!=' ');
            if(end==len) break;
            reverse(s,start,end-2);
            start = end;
        }
        reverse(s,start,end-1);
        reverse(s,0,len-1);
    }
    void reverse(string &s, int start, int end){
        for(int i=start, j = end;i<j;i++,j--){
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
};