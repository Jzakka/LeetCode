class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1, head);
        auto prev = dummy;
        ListNode* cursor = head;
        int cnt;
        for (cnt = 0; cnt < left-1; cnt++) {
            cursor = cursor->next;
            prev = prev->next;
        }

        vector<ListNode *> arr;
        for (; cnt < right - 1; cnt++) {
            arr.push_back(cursor);
            cursor = cursor->next;
        }
        arr.push_back(cursor);
        auto next = cursor->next;

        std::reverse(arr.begin(), arr.end());
        for (auto it = arr.begin(); it + 1 != arr.end(); it++) {
            (*it)->next = *(it + 1);
        }
        prev->next = arr.front();
        arr.back()->next = next;

        return dummy->next;
    }
};