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
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        auto node = head;
        while (node != nullptr) {
            vec.push_back(node);
            node = node->next;
        }

        int n = vec.size();
        int delta = n-1;
        int curIdx = 0;
        while (delta != 0) {
            cout << curIdx << " " << curIdx + delta << "\n";
            vec[curIdx]->next = vec[curIdx + delta];
            cout << "-\n";
            curIdx = curIdx + delta;
            cout << "curIdx: " << curIdx << "\n";
            delta = (-delta/abs(delta)) * (abs(delta) - 1);
            cout << "delta: " << delta << "\n";
        }
        vec[curIdx]->next = nullptr;
    }
};