//LeetCode 432. All O`one Data Structure
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <vector>
#include "mainHeader.h"
using namespace std;
class AllOne {
private:
    std::unordered_map<string, int >map_1;
    std::map<int, unordered_set<string>>map_2;
public:
    /** Initialize your data structure here. */
    AllOne() {
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(std::string key) {
        auto itr_1 = map_1.find(key);
        if (itr_1 == map_1.end()) {
            map_1[key] = 1;
            auto itr_2 = map_2.find(1);
            if (itr_2 == map_2.end()) {
                map_2[1] = unordered_set<string>();
            }
            map_2[1].insert(key);
        }
        else {

            int v = map_1[key];
            map_1[key]++;
            map_2[v].erase(key);
            if (map_2[v].empty())map_2.erase(v);
            auto itr_2 = map_2.find(v + 1);
            if (itr_2 == map_2.end()) {
                map_2[v + 1] = unordered_set<string>();
            }
            map_2[v + 1].insert(key);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(std::string key) {
        auto itr_1 = map_1.find(key);
        if (itr_1 == map_1.end())return;
        int v = map_1[key];
        if (v == 1) {
            map_1.erase(key);
            map_2[1].erase(key);
            if (map_2[1].empty())map_2.erase(1);
        }
        else {
            map_1[key]--;
            map_2[v].erase(key);
            if (map_2[v].empty())map_2.erase(v);
            auto itr_2 = map_2.find(v - 1);
            if (itr_2 == map_2.end()) {
                map_2[v - 1] = unordered_set<string>();
            }
            map_2[v - 1].insert(key);
        }
    }

    /** Returns one of the keys with maximal value. */
    std::string getMaxKey() {
        if (map_1.size() == 0)return "";
        auto itr = map_2.end();
        itr--;
        return *(itr->second.begin());
    }

    /** Returns one of the keys with Minimal value. */
    std::string getMinKey() {
        if (map_1.size() == 0)return "";
        auto itr = map_2.begin();
        return *(itr->second.begin());
    }
};