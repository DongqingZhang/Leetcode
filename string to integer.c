class Solution {
public:
    int myAtoi(string str) {
        int count = 0;
        int num = 0;
        int sign = 1;
        while(count < str.length() && str[count]==' ')
            count++;
        if (count == str.length()) return 0;
        if (str[count] == '-'){
            count++;
            sign = -1;
        }
        else if(str[count] == '+'){
            count++;
        }
        for (;count < str.length();count++){
            if (str[count] == ' '||str[count]<'0'||str[count]>'9') break;
            if (INT_MAX/10 < num||(INT_MAX/10 == num && INT_MAX%10 < (str[count] - '0'))){
                return sign == -1?INT_MIN:INT_MAX;
            }
            num = num*10+(str[count] - '0');
        }
        num *= sign;
        return num;
    }
};