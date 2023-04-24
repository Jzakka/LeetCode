
class Solution {
private:
    vector<int> input;
public:
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> nums;
        for (auto node = head; node != nullptr; node = node->next) {
            nums.push_back(node->val);
        }
        return sortedArrayToBST(nums);
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) {
        input = nums;
        return devideAndConquer(0, input.size());
    }

    TreeNode *devideAndConquer(int start, int end){
        int sz = end - start;
        if(sz < 1) {
            return nullptr;
        }
        else if (sz == 1) {
            return new TreeNode(input[start]);
        }
        int mid = (start + end) / 2;
        if (sz & 1) {
            TreeNode *node = new TreeNode(input[mid]);
            auto left = devideAndConquer(start, mid);
            auto right = devideAndConquer(mid + 1, end);
            node->left = left;
            node->right = right;
            return node;
        } else {
            auto left = devideAndConquer(start, mid);
            auto right = devideAndConquer(mid, end);

            if (sz == 2) {
                right->left = left;
                return right;
            }
            auto leafParent = right;
            while (leafParent->left->left != nullptr) {
                leafParent = leafParent->left;
            }
            auto leaf = leafParent->left;
            leaf->left = left;
            leaf->right = right;
            leafParent->left = nullptr;

            return leaf;
        }
    }
};