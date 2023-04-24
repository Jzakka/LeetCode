
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        auto cur1 = list1;
        auto cur2 = list2;
        vector<ListNode *> vec;

        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val < cur2->val) {
                vec.push_back(cur1);
                cur1 = cur1->next;
            } else {
                vec.push_back(cur2);
                cur2 = cur2->next;
            }
        }

        if (cur1 == nullptr) {
            while (cur2 != nullptr) {
                vec.push_back(cur2);
                cur2 = cur2->next;
            }
        } else if (cur2 == nullptr && cur1 != nullptr) {
            while (cur1 != nullptr) {
                vec.push_back(cur1);
                cur1 = cur1->next;
            }
        }

        for (auto it = vec.begin(); it != vec.end(); it++) {
            if (next(it) != vec.end()) {
                (*it)->next = *next(it);
            }
        }

        return vec.empty() ? NULL : *vec.begin();
    }
};