

class LFUCache {
private:
public:
    LFUCache(int capacity);
    int get(int key) { return -1; };
    void put(int key, int value);
};