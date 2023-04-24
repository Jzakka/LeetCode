class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x!=0 &&x %10 ==0)) return false;

        int sum = 0;
        int temp = x;
        while (x > sum) {
            sum = sum * 10 + x % 10;
            x = x / 10;

//            cout << sum << " " << x << "\n";
        }

        return x == sum || x==sum/10 ;
    }
};