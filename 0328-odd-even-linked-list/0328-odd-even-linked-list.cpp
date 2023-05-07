class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        auto node = head;
        int len = 0;
        while (node != nullptr) {
            node = node->next;
            len++;
        }

        if (len <= 2) {
            return head;
        }

        auto second = head->next;
        node = head;

        auto next = second;
        while (next->next) {
            node->next = next->next;
            node = next;
            next = node->next;
        }

        if (len & 1) {
            next->next = second;
            node->next = nullptr;
        } else {
            node->next = second;
        }

        return head;
    }
};