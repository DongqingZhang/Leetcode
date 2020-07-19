class Solution {
public:
    bool isStrobogrammatic(string num) {
        int len = num.length();
        if (len == 0) return true;
        for (int i = 0;i<len/2;i++){
            if (!isPair(num[i],num[len-1-i])) return false;
        }
        if (len%2) return (num[len/2] == '8'||num[len/2] == '1'||num[len/2] == '0');
        else return true;
    }
    bool isPair(char c1,char c2){
        if (c1!='0'&&c1!='1'&&c1!='6'&&c1!='8'&&c1!='9') return false;
        if (c2!='0'&&c2!='1'&&c2!='6'&&c2!='8'&&c2!='9') return false;
        if (c1=='0'||c1=='1'||c1=='8') return (c1==c2);
        if ((c1 == '6'&&c2 == '9')||(c1 == '9'&&c2 == '6')) return true;
        return false;
    }
};