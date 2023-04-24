
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        vector<ListNode *> vec;
        for (auto node = head; node != nullptr; node = node->next) {
            if (node->val != val) {
                vec.push_back(node);
            }
        }
        for (int i = 1; i < vec.size(); i++) {
            vec.at(i - 1)->next = vec.at(i);
        }
        if (!vec.empty()) {
            vec.back()->next = nullptr;
            return vec.front();
        }
        return nullptr;
    }
};