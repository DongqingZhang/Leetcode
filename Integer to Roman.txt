class Solution {
public:
    string intToRoman(int num) {
        vector<int> digits;
        string res;
        int units[] = {1,5,10,50,100,500,1000};
        string roman = "MDCLXVI";
        int i = 6;
        while(i >= 0){
            cout<<num/units[i]<<endl;
            digits.push_back(num/units[i]);
            num %= units[i];
            i -= 2;
        }
        for (int j = 0;j<digits.size();j++){
            if (j == 0){
                for (int k = 0;k<digits[j];k++) res.push_back('M');
            }
            else{
                if (digits[j] > 0&&digits[j] <= 3){
                    for (int k = 0;k<digits[j];k++) res.push_back(roman[2*j]);
                }
                if (digits[j] == 4){
                    res.push_back(roman[2*j]);
                    res.push_back(roman[2*j-1]);
                }
                if (digits[j] == 5)
                    res.push_back(roman[2*j-1]);
                if (digits[j] > 5&&digits[j] < 9){
                    res.push_back(roman[2*j-1]);
                    for (int k = 0;k<digits[j]-5;k++) res.push_back(roman[2*j]);
                }
                if (digits[j] == 9){
                    res.push_back(roman[2*j]);
                    res.push_back(roman[2*j-2]);
                }
            }
        }
        return res;
    }
};