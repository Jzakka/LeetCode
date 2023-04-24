class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *prev = new ListNode(-1, head);
        ListNode *res = prev;
        ListNode *cursor = head;
        for (; cursor != nullptr; prev = prev->next, cursor = cursor->next) {
            if (cursor->val >= x) {
                break;
            }
        }
        ListNode *left = prev;
        ListNode *right = cursor;
        for (; cursor != nullptr; prev = prev->next, cursor = cursor->next) {
            while (cursor!= nullptr && cursor->val < x) {
                prev->next = cursor->next;
                cursor->next = right;
                left->next = cursor;
                left = cursor;
                cursor = prev->next;
            }
            if (cursor == nullptr) {
                break;
            }
        }
        return res->next;
    }
};