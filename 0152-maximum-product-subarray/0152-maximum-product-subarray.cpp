class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstMinAccProd = 1;
        int accProd = 1;
        int maxProd = INT32_MIN;
        for (int i = 0; i < nums.size(); i++) {
            accProd *= nums[i];
            int prod;
            if (accProd == 0) {
                firstMinAccProd = 1;
                accProd = 1;
                prod = 0;
            } else if (accProd < 0) {
                if (firstMinAccProd == 1) {
                    firstMinAccProd = accProd;
                    prod = accProd;
                } else {
                    prod = accProd / firstMinAccProd;
                }
            } else {
                prod = accProd;
            }
            maxProd = max(maxProd, prod);
        }
        return maxProd;
    }
};