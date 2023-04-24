/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto fix = head;
        if(fix == nullptr) return nullptr;
        for (auto cursor = head->next; cursor != nullptr; cursor = cursor->next) {
            if (fix->val != cursor->val) {
                fix->next = cursor;
                fix = cursor;
            }
        }
        fix->next = nullptr;
        return head;
    }
};