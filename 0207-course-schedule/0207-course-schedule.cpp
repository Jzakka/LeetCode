
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> nextCourses(numCourses);
        for (auto &prerequisite: prerequisites) {
            int dest = prerequisite.front();
            int src = prerequisite.back();

            nextCourses.at(src).push_back(dest);
        }

        vector<bool> finished(numCourses);
        vector<bool> visited(numCourses);
        for (int i = 0; i < numCourses; i++) {
            if(hasCycle(i, nextCourses, finished, visited)){
                return false;
            }
        }

        return true;
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
};