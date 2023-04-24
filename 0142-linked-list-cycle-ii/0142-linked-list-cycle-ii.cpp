/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto v = head, w = head;

        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        do {
            v = v->next;
            w = w->next->next;
        } while (w != nullptr && w->next != nullptr && v != w);

        if (w == nullptr || w->next == nullptr) {
            return nullptr;
        }

        w = head;
        while (v != w) {
            v = v->next;
            w = w->next;
        }

        return v;
    }
};