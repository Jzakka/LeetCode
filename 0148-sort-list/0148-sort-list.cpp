class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (!(fast->next == nullptr || fast->next->next == nullptr)) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto midNext = slow->next;
        slow->next = nullptr;

        auto left = sortList(head);
        auto right = sortList(midNext);


        ListNode* node;
        if (left->val < right->val) {
            node = left;
            left = left->next;
        } else {
            node = right;
            right = right->next;
        }
        auto res = node;

        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                node->next = left;
                node = left;
                left = left->next;
            } else {
                node->next = right;
                node = right;
                right = right->next;
            }
        }
        if (right == nullptr) {
            node->next = left;
        } else {
            node->next = right;
        }

        return res;
    }
};