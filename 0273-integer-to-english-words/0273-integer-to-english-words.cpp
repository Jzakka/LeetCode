
class Solution {
public:
    string numberToWords(int num) {
        if(!num) return "Zero";

        int billionCnt = num / 1'000'000'000;
        int millionCnt = num % 1'000'000'000 / 1'000'000;
        int thousandCnt = num % 1'000'000 / 1'000;
        int oneCnt = num % 1'000;

        string billionSpell = billionCnt ? spellUnitInteger(billionCnt) + "Billion " : "";
        string millionSpell = millionCnt ? spellUnitInteger(millionCnt) + "Million " : "";
        string thousandSpell = thousandCnt ? spellUnitInteger(thousandCnt) + "Thousand " : "";
        string oneSpell = spellUnitInteger(oneCnt);
        string result = billionSpell + millionSpell + thousandSpell + oneSpell;

        result.erase(result.length() - 1, 1);
        return result;
    }

    // cnt is in [0,999)
    string spellUnitInteger(int cnt) {
        if (cnt == 0) {
            return "";
        }
        int hundredCnt = cnt / 100;
        int tenCnt = cnt % 100 / 10;
        int oneCnt = cnt % 10;

        if (tenCnt == 1) {
            return (hundredCnt ? oneSpell(hundredCnt) + "Hundred " : "")
                   + tenSpell(oneCnt);
        } else if (oneCnt == 0) {
            return (hundredCnt ? oneSpell(hundredCnt) + "Hundred " : "")
                   + tensSpell(tenCnt);
        }
        return (hundredCnt ? oneSpell(hundredCnt) + "Hundred " : "")
               + (tenCnt ? tensSpell(tenCnt) : "")
               + (oneCnt ? oneSpell(oneCnt) : "");
    }

    string tenSpell(int oneCnt){
        switch (oneCnt) {
            case 0:
                return "Ten ";
            case 1:
                 return "Eleven ";
            case 2:
                 return "Twelve ";
            case 3:
                 return "Thirteen ";
            case 4:
                 return "Fourteen ";
            case 5:
                 return "Fifteen ";
            case 6:
                 return "Sixteen ";
            case 7:
                 return "Seventeen ";
            case 8:
                 return "Eighteen ";
            default:
                 return "Nineteen ";
        }
        return "";
    }

    string tensSpell(int tenCnt){
        switch (tenCnt) {
            case 0:
                return "";
            case 2:
                return "Twenty ";
            case 3:
                 return "Thirty ";
            case 4:
                 return "Forty ";
            case 5:
                 return "Fifty ";
            case 6:
                 return "Sixty ";
            case 7:
                 return "Seventy ";
            case 8:
                 return "Eighty ";
            default:
                 return "Ninety ";
        }
        return "";
    }

    string oneSpell(int oneCnt){
        switch (oneCnt) {
            case 1:
                return "One ";
            case 2:
                 return "Two ";
            case 3:
                 return "Three ";
            case 4:
                 return "Four ";
            case 5:
                 return "Five ";
            case 6:
                 return "Six ";
            case 7:
                 return "Seven ";
            case 8:
                 return "Eight ";
            case 9:
                 return "Nine ";
        }
        return "";
    }
};