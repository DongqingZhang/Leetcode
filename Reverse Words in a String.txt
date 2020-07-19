class Solution {
public:
    void reverseWords(string &s) {
        int i=0,j=0,l=s.length(),wordCnt = 0;;
        while(i<l && s[i]==' ') i++;
        while(true){
            int start = j;
            while(i<l && s[i]!=' ') s[j++]=s[i++];
            reverseStr(s, start, j-1);
            wordCnt++;
            if(i<l) s[j++]=s[i++];
            else break;
            while(i<l && s[i]==' ') i++;
            if(i==l){j--;break;}
        }
        reverseStr(s,0,max(0,j-1));
        s.resize(j);
    }
    void reverseStr(string &s, int start, int end){
        for(int i=start,j=end;i<j;i++,j--){
            char tmp = s[i];
            s[i]=s[j];
            s[j]=tmp;
        }
    }
};