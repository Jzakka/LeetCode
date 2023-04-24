class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        int thousand = num / 1000;
        int hundred = (num % 1000) / 100;
        int ten = (num % 100) / 10;
        int one = (num % 10);


        for (int i = 0; i < thousand; ++i) {
            result.append("M");
        }

        if (hundred <= 3) {
            for (int i = 0; i < hundred; ++i) {
                result.append("C");
            }
        } else if (hundred == 4) {
            result.append("CD");
        } else if (hundred == 5) {
            result.append("D");
        } else if (hundred <= 8) {
            result.append("D");
            for (int i = 0; i < hundred-5; ++i) {
                result.append("C");
            }
        }else{
            result.append("CM");
        }

        if (ten <= 3) {
            for (int i = 0; i < ten; ++i) {
                result.append("X");
            }
        } else if (ten == 4) {
            result.append("XL");
        } else if (ten == 5) {
            result.append("L");
        } else if (ten <= 8) {
            result.append("L");
            for (int i = 0; i < ten-5; ++i) {
                result.append("X");
            }
        }else{
            result.append("XC");
        }

        if (one <= 3) {
            for (int i = 0; i < one; ++i) {
                result.append("I");
            }
        } else if (one == 4) {
            result.append("IV");
        } else if (one == 5) {
            result.append("V");
        } else if (one <= 8) {
            result.append("V");
            for (int i = 0; i < one-5; ++i) {
                result.append("I");
            }
        }else{
            result.append("IX");
        }

        return result;
    }
};