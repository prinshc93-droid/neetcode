
class LRUCache {
public:
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        auto it = mp[key];
        int value = it->second;

        // Move recently used element to front
        dll.erase(it);
        dll.push_front({key, value});

        mp[key] = dll.begin();

        return value;
    }

    void put(int key, int value) {

        // If key already exists
        if (mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        }

        // Insert at front (Most Recently Used)
        dll.push_front({key, value});
        mp[key] = dll.begin();

        // Remove Least Recently Used if capacity exceeded
        if (dll.size() > capacity) {
            auto last = dll.back();

            mp.erase(last.first);
            dll.pop_back();
        }
    }
};
