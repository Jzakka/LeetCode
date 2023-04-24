class Solution {
public:
    int search(vector<int> &nums, int target) {
        int sz = nums.size();
        int r = sz - 1;
        int l = 0;
        int mid = (r + l) / 2;

        while (l < r){
            mid = (l + r) / 2;
            if(nums.at(mid) > nums.at(r)) l = mid+1;
            else r = mid;
        }
        int pivot = sz - l;

        l = (0 + sz - pivot) % sz;
        r = (sz - 1 + sz - pivot) % sz;
        mid = ((l + pivot) % sz + (r + pivot) % sz) / 2;
        mid = (mid + (sz - pivot)) % sz;
        while (nums.at(l) < nums.at(r)) {
            if (nums.at(mid) > target) {
                r = mid;
            } else if (nums.at(mid) < target) {
                l = (mid + 1) % sz;
            } else {
                break;
            }
            mid = ((l + pivot) % sz + (r + pivot) % sz) / 2;
            mid = (mid + (sz - pivot)) % sz;
        }
        return nums.at(mid) == target ? mid : -1;
    }
};
