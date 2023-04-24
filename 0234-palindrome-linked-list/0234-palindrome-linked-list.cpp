
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        auto slow = head, fast = head;

        ListNode *prev = NULL, *prePrev = NULL;
        while (fast && fast->next) {
            prePrev = prev;
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            if (prev && prePrev) {
                prev->next = prePrev;
            }
        }
        auto reverseScanner = prev;
        if (fast) {
            slow = slow->next;
        }
        head->next = NULL;
        while (slow) {
            if (reverseScanner->val != slow->val) {
                return false;
            }
            reverseScanner = reverseScanner->next;
            slow = slow->next;
        }
        return true;
    }
};
