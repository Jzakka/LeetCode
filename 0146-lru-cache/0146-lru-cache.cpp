class LRUCache {
private:
    unordered_map<int, pair<int,int>> cache;
    vector<int> numKey = vector<int>(200'000);

    int size;
    int evictIdx = 0;
    int commandNum = 0;
public:
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        } else {
            numKey[cache[key].second] = -1;
            cache[key].second = commandNum;
            numKey[commandNum++] = key;
            return cache[key].first;
        }
    }

    void put(int key, int value) {
        if (cache.find(key)==cache.end() && cache.size() == size) {
            while (numKey[evictIdx] == -1) {
                evictIdx++;
            }
            int evictKey = numKey[evictIdx];
            numKey[cache[evictKey].second] = -1;
            cache.erase(evictKey);
        } else if(cache.find(key)!=cache.end()) {
            numKey[cache[key].second] = -1;
        }
        cache[key] = {value, commandNum};
        numKey[commandNum++] = key;
    }
};