class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        vector<ListNode*> nodes;
        for (auto node = head; node != nullptr; node = node->next) {
            nodes.push_back(node);
        }

        int sz = nodes.size();
        for (int i = sz - 1; i > 0; i--) {
            nodes.at(i)->next = nodes.at(i - 1);
        }
        nodes.front()->next = nullptr;
        return nodes.back();
    }
};
