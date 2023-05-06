class Solution {
public:
    bool isPowerOfThree(int n) {
        unordered_set<int> powOf3;
        powOf3.insert(1);
        powOf3.insert(3);
        powOf3.insert(9);
        powOf3.insert(27);
        powOf3.insert(81);
        powOf3.insert(243);
        powOf3.insert(729);
        powOf3.insert(2187);
        powOf3.insert(6561);
        powOf3.insert(19683);
        powOf3.insert(59049);
        powOf3.insert(177147);
        powOf3.insert(531441);
        powOf3.insert(1594323);
        powOf3.insert(4782969);
        powOf3.insert(14348907);
        powOf3.insert(43046721);
        powOf3.insert(129140163);
        powOf3.insert(387420489);
        powOf3.insert(1162261467);

        return powOf3.find(n) != powOf3.end();
    }
};