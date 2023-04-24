
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        vector<ListNode *> result;

        for (auto cursor = head; cursor != nullptr; cursor = cursor->next) {
            result.push_back(cursor);
        }
        result.push_back(nullptr);

        int sz = result.size();
        for (int i = 0; i < sz; i++) {
            if (i != 0 && i % k == 0) {
                reverse(result.begin() + i - k, result.begin() + i);
            }
        }
        for (auto it = result.begin(); it != result.end(); it++) {
            if (next(it) != result.end()) {
                (*it)->next = *next(it);
            }
        }

        return result.empty() ? NULL : result.front();
    }
};