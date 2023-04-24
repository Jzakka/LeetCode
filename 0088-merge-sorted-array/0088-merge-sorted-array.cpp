class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m);
        for (int i = 0; i < m; i++) {
            temp[i] = nums1[i];
        }

        int i,j,idx;
        i = j = idx = 0;
        while (i < m && j < n) {
            int num1 = temp[i];
            int num2 = nums2[j];
            if (num1 < num2) {
                nums1[idx] = num1;
                i++;
            } else {
                nums1[idx] = num2;
                j++;
            }
            idx++;
        }
        for (; i < m; i++,idx++) {
            nums1[idx] = temp[i];
        }
        for (; j < n; j++, idx++) {
            nums1[idx] = nums2[j];
        }
    }
};
