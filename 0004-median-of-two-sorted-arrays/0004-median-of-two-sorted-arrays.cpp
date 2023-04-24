class Solution {
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::vector<int> temp;
        if (nums1.size() > nums2.size()) {
            temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }

        int len1 = nums1.size();
        int len2 = nums2.size();

        if (len1 == 0) {
            return (len1 + len2) % 2 == 0 ? (nums2.at(len2 / 2) + nums2.at(len2 / 2 - 1)) / 2.0 : nums2.at(len2 / 2);
        } else if (len2 == 0) {
            return (len1 + len2) % 2 == 0 ? (nums1.at(len1 / 2) + nums1.at(len1 / 2 - 1)) / 2.0 : nums1.at(len1 / 2);
        }

        int totalHalf = (len1 + len2) / 2;

        int low = 0;
        int high = totalHalf;

        int cut1 = len1 >= totalHalf ? (0 + totalHalf) / 2 : len1;
        int cut2 = totalHalf - cut1;
        int r1;
        int l1;
        int l2;
        int r2;
        calcLeftAndRight(nums1, nums2, len1, len2, cut1, cut2, r1, l1, l2, r2);

        while (l1 > r2 || l2 > r1) {
            if (l1 > r2) {
                high = cut1 - 1;
                cut1 = (low + high) / 2;
                cut2 = totalHalf - cut1;

                calcLeftAndRight(nums1, nums2, len1, len2, cut1, cut2, r1, l1, l2, r2);
            } else {
                low = cut1 + 1;
                cut1 = (low + high) / 2;
                cut2 = totalHalf - cut1;

                calcLeftAndRight(nums1, nums2, len1, len2, cut1, cut2, r1, l1, l2, r2);
            }
        }

        if ((len1 + len2) % 2 == 0) {
            return (std::max(l1, l2) + std::min(r1, r2)) / 2.0;
        } else
            return std::min(r1, r2);
    }

private:
    void
    calcLeftAndRight(std::vector<int> &nums1, std::vector<int> &nums2, int len1, int len2, int cut1, int cut2, int &r1,
                     int &l1, int &l2,
                     int &r2) const {
        r1 = cut1 == len1 ? INT32_MAX : nums1.at(cut1);
        l1 = cut1 == 0 ? INT32_MIN : nums1.at(cut1 - 1);
        l2 = cut2 == 0 ? INT32_MIN : nums2.at(cut2 - 1);
        r2 = cut2 == len2 ? INT32_MAX : nums2.at(cut2);
    }
};