
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        vector<ListNode *> result;
        
        for (auto cursor = head; cursor != nullptr; cursor = cursor->next) {
            result.push_back(cursor);
        }

        int sz = result.size();
        for (int i = 0; i < sz; i++) {
            if (i & 1) {
                auto temp = result[i];
                result[i] = result[i - 1];
                result[i - 1] = temp;
            }
        }
        for (auto it = result.begin(); it != result.end(); it++) {
            if (next(it) == result.end()) {
                (*it)->next = nullptr;
            } else {
                (*it)->next = *next(it);
            }
        }

        return result.empty() ? NULL : result.front();
    }
};