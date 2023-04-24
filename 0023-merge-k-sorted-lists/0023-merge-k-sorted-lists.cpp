
class Solution {
public:
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<ListNode *> result;
        priority_queue<ListNode *, vector<ListNode *>, cmp> minQ;
        int lsSz = lists.size();

        for (int i = 0; i < lsSz; i++) {
            if(lists[i]==nullptr) continue;
            minQ.push(lists[i]);
        }

        while (!minQ.empty()) {
            auto min = minQ.top();
            minQ.pop();
            result.push_back(min);
            min = min->next;
            if (min != nullptr)minQ.push(min);
        }

        for (auto it = result.begin(); it != result.end(); it++) {
            if (next(it) == result.end())
                (*it)->next = nullptr;
            else (*it)->next = *next(it);
        }

        return result.empty() ? NULL : result.front();
    }
};