
struct Building {
    int left;
    int right;
    int height;

    Building(int left, int right, int height) : left(left), right(right), height(height) {}
};

struct CompareRight {
    bool operator()(const Building *a, const Building *b) const {
        if (a->right == b->right) {
            if (a->height == b->height) {
                return a->left < b->left;
            }
            return a->height < b->height;
        }
        return a->right > b->right;
    }
};

struct CompareHeight {
    bool operator()(const Building *a, const Building *b) const {
        if (a->height == b->height) {
            if (a->right == b->right) {
                return a->left < b->left;
            }
            return a->right < b->right;
        }
        return a->height < b->height;
    }
};

class Solution {
private:
    vector<vector<int>> result;
    vector<Building *> buildingVector;
    set<Building *, CompareRight> minRight;
    set<Building *, CompareHeight> maxHeight;
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        auto ground = new Building(0, INT32_MAX, 0);

        for (auto &building: buildings) {
            buildingVector.push_back(new Building(building.at(0), building.at(1), building.at(2)));
        }
        minRight.insert(ground);
        maxHeight.insert(ground);

        Building *minRightTop;
        for (auto &building: buildingVector) {
            while ((minRightTop = *(prev(minRight.end()))),
                    maxHeight.size() > 1 && minRightTop->right < building->left) {
                removeBuilding(minRightTop);
            }
            addBuilding(building);
        }
        while ((minRightTop = *(prev(minRight.end()))), minRight.size() > 1) {
            removeBuilding(minRightTop);
        }

        return result;
    }

    void removeBuilding(Building *minRightTop) {
        auto it = maxHeight.find(minRightTop);
        vector<int> rightBottom = {minRightTop->right, (*prev(it))->height};

        for (it = next(it); it != maxHeight.end(); it++) {
            if ((*it)->height >= minRightTop->height
                && (*it)->left <= rightBottom.at(0)
                && (*it)->right >= rightBottom.at(0)) {
                minRight.erase(minRightTop);
                maxHeight.erase(minRightTop);
                return;
            }
        }
        minRight.erase(minRightTop);
        maxHeight.erase(minRightTop);
        if (!result.empty() && result.back().at(0) == rightBottom.at(0)) {
            result.back().at(1) = rightBottom.at(1);
        } else {
            result.emplace_back(rightBottom);
        }
    }

    void addBuilding(Building *building) {
        auto highest = *prev(maxHeight.end());
        if (highest->height < building->height) {
            if (!result.empty() && result.back().at(0) == building->left) {
                result.back().at(1) = building->height;
            } else {
                result.push_back({building->left, building->height});
            }
        }
        minRight.insert(building);
        maxHeight.insert(building);
    }
};