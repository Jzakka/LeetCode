class Solution {
public:
    struct Number {
        int smallerCnt = 0;
        int number;

    public:
        Number(int number) : number(number){}

        bool operator < (const Number &num) const {
            return this->number < num.number;
        }
    };

    vector<Number *> mergeSort(const vector<Number *> &arr, int start, int end) {
        if (start + 1 == end) {
            return {arr.at(start)};
        }
        int mid = (start + end) / 2;
        auto left = mergeSort(arr, start, mid);
        auto right = mergeSort(arr, mid, end);
        auto leftIt = left.begin();
        auto rightIt = right.begin();

        vector<Number *> res(end - start);
        int i = 0;
        int leftAccPoint = 0;
        while (leftIt != left.end() && rightIt != right.end()) {
            auto minimum = (*leftIt)->number <= (*rightIt)->number ? *leftIt : *rightIt;
            if (minimum == *leftIt) {
                (*leftIt)->smallerCnt += leftAccPoint;
                leftIt++;
            } else {
                leftAccPoint++;
                rightIt++;
            }
            res.at(i++) = minimum;
        }

        if (leftIt == left.end() && rightIt != right.end()) {
            while (rightIt != right.end()) {
                res.at(i++) = *rightIt++;
            }
        } else if (leftIt != left.end() && rightIt == right.end()) {
            while (leftIt != left.end()) {
                (*leftIt)->smallerCnt += leftAccPoint;
                res.at(i++) = *leftIt++;
            }
        }

        return res;
    }

    vector<int> countSmaller(vector<int> &nums) {
        vector<Number *> originOrder;
        vector<Number *> numArr;
        for (int i = 0; i < nums.size(); i++) {
            auto number = new Number(nums.at(i));
            numArr.push_back(number);
            originOrder.push_back(number);
        }

        mergeSort(numArr, 0, nums.size());

        vector<int> res(nums.size());
        for (int i = 0; i < res.size(); i++) {
            res.at(i) = originOrder.at(i)->smallerCnt;
        }
        return res;
    }
};