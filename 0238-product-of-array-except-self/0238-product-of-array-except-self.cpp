class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        recursive(1, 0, res, nums);
        return res;
    }

    int recursive(int prefixProd, int idx, vector<int>& res, const vector<int>& nums){
        if (idx == res.size()) {
            return 1;
        }

        int suffixProd = recursive(prefixProd * nums.at(idx), idx + 1, res, nums);
        res.at(idx) = prefixProd * suffixProd;
        return nums.at(idx) * suffixProd;
    }
};