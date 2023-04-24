class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> nextCourses(numCourses);
        vector<bool> hasParent(numCourses);
        for (auto &prerequisite: prerequisites) {
            int dest = prerequisite.front();
            int src = prerequisite.back();

            nextCourses.at(src).push_back(dest);
            hasParent.at(dest) = true;
        }

        vector<bool> finished(numCourses);
        vector<bool> visited(numCourses);
        for (int i = 0; i < numCourses; i++) {
            if(hasCycle(i, nextCourses, finished, visited)){
                return {};
            }
        }

        vector<int> levels(numCourses, -1);
        for (int i = 0; i < numCourses; i++) {
            if(!hasParent.at(i)){
                bfs(i, nextCourses, levels);
            }
        }

        vector<vector<int>> levelAndCourses(numCourses);
        for (int i = 0; i < numCourses; i++) {
            int level = levels.at(i);
            levelAndCourses.at(level).push_back(i);
        }
        auto it = levelAndCourses.begin();
        vector<int> res;
        while (!(it == levelAndCourses.end() || (*it).empty())) {
            for (auto course: (*it)) {
                res.push_back(course);
            }
            it++;
        }
        return res;
    }

    bool hasCycle(int pos, vector<vector<int>> &nextCourses, vector<bool> &finished, vector<bool> &visited) {
        if(visited.at(pos)){
            return !finished.at(pos);
        }

        visited.at(pos) = true;
        for (auto nextCourse: nextCourses.at(pos)) {
            if (hasCycle(nextCourse, nextCourses, finished, visited)) {
                return true;
            }
        }

        finished.at(pos) = true;
        return false;
    }

    void bfs(int start, vector<vector<int>>& nextCourses, vector<int>& levels){
        queue<int> Q;
        Q.push(start);

        int level = 0;
        while (!Q.empty()){
            int qLen = Q.size();
            for (int i = 0; i < qLen; i++) {
                int front = Q.front();
                Q.pop();
                levels.at(front) = max(levels.at(front), level);
                for (auto nextCourse: nextCourses.at(front)) {
                    Q.push(nextCourse);
                }
            }
            level++;
        }
    }
};