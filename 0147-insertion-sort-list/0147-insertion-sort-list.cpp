
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        vector<ListNode*> vec;
        for (auto node = head; node != nullptr; node = node->next) {
            vec.push_back(node);
        }

        for (int i = 1; i < vec.size(); i++) {
            while (i - 1 >= 0 && vec[i - 1]->val > vec[i]->val) {
                swap(vec[i - 1], vec[i]);
                i--;
            }
        }

        for (int i = 0; i < vec.size() - 1; i++) {
            vec[i]->next = vec[i + 1];
        }
        vec[vec.size() - 1]->next = nullptr;
        return vec[0];
    }
};