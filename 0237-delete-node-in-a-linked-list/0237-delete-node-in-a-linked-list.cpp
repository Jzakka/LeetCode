class Solution {
public:
    void deleteNode(ListNode* node) {
        while (node) {
            node->val = node->next->val;
            if (!node->next->next) {
                node->next = nullptr;
            }
            node = node->next;
        }
    }
};