class Solution {
public:
    string addBinary(string a, string b) {
    int carry = 0;
    string res;
    int bitRes;
    int l1 = a.length();
    int l2 = b.length();
    int limit1 = max(l1,l2);
    for (int i = 1;i <= limit1;i++){
        if (l1 - i >= 0&&l2 - i >= 0){
            bitRes = (a[l1 - i] - '0') + (b[l2 - i] - '0') + carry;
            cout<<bitRes<<endl;
            if (bitRes > 1)
                carry = 1;
            else
                carry = 0;
            res.append(1,(char)(bitRes%2+'0'));
        }
        else if(l1 - i >= 0){
            bitRes = a[l1 - i] - '0' + carry;
            if (bitRes > 1)
                carry = 1;
            else
                carry = 0;
            res.append(1,(char)(bitRes%2+'0'));
        }
        else if(l2 - i >= 0){
            bitRes = b[l2 - i] - '0' + carry;
            if (bitRes > 1)
                carry = 1;
            else
                carry = 0;
            res.append(1,(char)(bitRes%2+'0'));
        }
    }
    if (carry == 1)
        res.append(1,'1');
    
    std::reverse(res.begin(),res.end());
    return res;
    }
};