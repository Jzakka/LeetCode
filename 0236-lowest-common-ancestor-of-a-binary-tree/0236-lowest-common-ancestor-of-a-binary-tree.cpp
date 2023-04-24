
class Solution {
private:
    unordered_map<int, TreeNode *[17]> parent;
    unordered_map<int, int> level;
    int n = 0;
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        setLevelAndAncestors(root);
        int pLv, qLv;
        auto deeper = getDeeper(p, q, pLv, qLv);
        auto shallower = deeper == q ? p : q;
        equalizeLevel(deeper, level[shallower->val]);
        return getCommonAncestor(deeper, shallower);
    }

    void setLevelAndAncestors(TreeNode *root) {
        setLevelAndParent(root);
        setAncestor(root);
    }

    void setLevelAndParent(TreeNode *root) {
        queue<TreeNode *> Q;
        Q.push(root);

        int lvl = 0;
        while (!Q.empty()) {
            int qLen = Q.size();
            for (int i = 0; i < qLen; i++) {
                auto node = Q.front();
                level[node->val] = lvl;
                Q.pop();
                n++;

                if (node->left) {
                    parent[node->left->val][0] = node;
                    Q.push(node->left);
                }
                if (node->right) {
                    parent[node->right->val][0] = node;
                    Q.push(node->right);
                }
            }
            lvl++;
        }
    }

    void setAncestor(TreeNode *node) {
        const int MAX_EXP = ceil(log2(n));
        for (int i = 1; i < MAX_EXP; i++) {
            auto ancestors = parent[node->val];
            if (!ancestors[i - 1]) {
                continue;
            }
            parent[node->val][i] = parent[ancestors[i - 1]->val][i - 1];
        }
        if (node->left) {
            setAncestor(node->left);
        }
        if (node->right) {
            setAncestor(node->right);
        }
    }

    TreeNode *getDeeper(TreeNode *p, TreeNode *q, int &pLv, int &qLv) {
        pLv = level[p->val];
        qLv = level[q->val];

        return pLv > qLv ? p : q;
    }

    void equalizeLevel(TreeNode *&node, int targetLevel) {
        int levelDiff = level[node->val] - targetLevel;
        int i = 0;
        while (levelDiff) {
            if (levelDiff & 1) {
                node = parent[node->val][i];
            }
            levelDiff >>= 1;
            i++;
        }
    }

    TreeNode *getCommonAncestor(TreeNode *p, TreeNode *q) {
        while (p != q) {
            p = parent[p->val][0];
            q = parent[q->val][0];
        }
        return p;
    }
};