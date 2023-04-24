class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        int mem = -500;
        vector<ListNode*> nodes;
        auto fix = head;
        if(fix== nullptr) return nullptr;
        for (auto cur = head -> next; cur != nullptr; mem=fix->val, fix = cur, cur = cur->next) {
            if (fix->val != cur->val && mem != fix->val) {
                nodes.push_back(fix);
            }
        }
        if (mem != fix->val) {
            nodes.push_back(fix);
        }
        if(nodes.empty()) return nullptr;
        auto it = nodes.begin();
        for (; it + 1 != nodes.end(); it++) {
            (*it)->next = *(it + 1);
        }
        (*it)->next = nullptr;
        return nodes.front();
    }
};