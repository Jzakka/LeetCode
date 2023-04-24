class MedianFinder {
private:
    multiset<int> nums;
    multiset<int>::iterator med_it = nums.end();
public:
    MedianFinder() {

    }

    void addNum(int num) {
        nums.insert(num);
        if (med_it == nums.end()) {
            med_it = nums.begin();
        } else {
            int med = *med_it;
            if (nums.size() & 1) {
                if (num < med) {
                    med_it = prev(med_it);
                }
            } else {
                if (num >= med) {
                    med_it = next(med_it);
                }
            }
        }
    }

    double findMedian() {
        return nums.size() & 1 ? *med_it : (double )(*med_it + *prev(med_it)) / 2;
    }
};