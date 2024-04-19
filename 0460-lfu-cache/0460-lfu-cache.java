class LFUCache {
    public int time = 0;
    int capacity;
    Map<Integer, Integer> cache = new HashMap<>();
    int[] frequency = new int[100_001];
    int[] lastAccess = new int[100_001];
    TreeSet<Priority> priorities = new TreeSet<>();

    public LFUCache(int capacity) {
        this.capacity = capacity;
        Arrays.fill(lastAccess, - 1);
    }

    public int get(int key) {
        Integer val = cache.get(key);
        if (val == null) {
            return -1;
        }
        priorities.remove(new Priority(frequency[key], lastAccess[key], key));
        frequency[key]++;
        lastAccess[key] = time++;
        priorities.add(new Priority(frequency[key], lastAccess[key], key));
        return val;
    }

    public void put(int key, int value) {
        if (!cache.containsKey(key) && cache.size() >= capacity) {
            evict();
        }
        priorities.remove(new Priority(frequency[key], lastAccess[key], key));
        frequency[key]++;
        lastAccess[key] = time++;
        priorities.add(new Priority(frequency[key], lastAccess[key], key));
        cache.put(key, value);
    }

    private void evict() {
        Priority eviction = priorities.first();
        priorities.remove(eviction);
        int evictionKey = eviction.key;
        frequency[evictionKey] = 0;
        lastAccess[evictionKey] = -1;
        cache.remove(evictionKey);
    }
}

class Priority implements Comparable<Priority> {
    int frequency;
    int lastAccess;
    int key;

    public Priority(int frequency, int lastAccess, int key) {
        this.frequency = frequency;
        this.lastAccess = lastAccess;
        this.key = key;
    }

    @Override
    public int compareTo(Priority o) {
        if (frequency == o.frequency) {
            return lastAccess - o.lastAccess;
        }
        return frequency - o.frequency;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Priority priority = (Priority) o;
        return frequency == priority.frequency && lastAccess == priority.lastAccess && key == priority.key;
    }

    @Override
    public int hashCode() {
        return Objects.hash(frequency, lastAccess, key);
    }
}