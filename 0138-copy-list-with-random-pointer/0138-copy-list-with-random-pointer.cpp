class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }
        map<Node *, Node *> map;
        set<pair<Node *, Node *>> visitedNext;
        set<pair<Node *, Node *>> visitedRand;
        map[head] = new Node(head->val);
        DFS(map, visitedNext, visitedRand, head, map[head]);
        return map[head];
    }

    void DFS(map<Node *, Node *> &map, set<pair<Node *, Node *>> &visitedNext,
             set<pair<Node *, Node *>> &visitedRand, Node *origin, Node *copied) {
        if (origin->next) {
            if (visitedNext.find({origin, origin->next}) == visitedNext.end()) {
                visitedNext.insert({origin, origin->next});
                Node *copyNext;
                if (map.find(origin->next) != map.end()) {
                    copyNext = map[origin->next];
                } else {
                    copyNext = new Node(origin->next->val);
                    map[origin->next] = copyNext;
                }
                copied->next = copyNext;
                DFS(map, visitedNext,visitedRand, origin->next, copyNext);
            }
        }
        if (origin->random) {
            if (visitedRand.find({origin, origin->random}) == visitedRand.end()) {
                visitedRand.insert({origin, origin->random});
                Node *copyNext;
                if (map.find(origin->random) != map.end()) {
                    copyNext = map[origin->random];
                } else {
                    copyNext = new Node(origin->random->val);
                    map[origin->random] = copyNext;
                }
                copied->random = copyNext;
                DFS(map, visitedNext,visitedRand, origin->random, copyNext);
            }
        }
    }
};