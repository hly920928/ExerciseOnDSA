#pragma once
 
#include<set>
#include<unordered_map>
class cacheInfo {
public:
    int key;
    int val;
    int fre;
    unsigned int lastTime;
    cacheInfo(int k=INT_MIN,int v = INT_MIN, int f =0,int t=0) :key(k),val(v), fre(f), lastTime(t){};
    bool operator<(const cacheInfo&b) const{
        if (fre < b.fre)return true;
        if (fre > b.fre)return false;
        if (lastTime< b.lastTime)return true;
        if (lastTime > b.lastTime)return false;
        return false;
    }
};
class LFUCache {
private:
    std::unordered_map<int , cacheInfo>keyTable;
    std::set<cacheInfo>cacheInfoTable;
    int now_size;
    int cap;
    unsigned int clock;
    void removeLast() {
        cacheInfo target = *cacheInfoTable.begin();
        keyTable.erase(target.key);
        cacheInfoTable.erase(target);
    };
public:
    LFUCache(int capacity):cap(capacity), now_size(0), clock(0){

    }

    int get(int key) {
        if (cap == 0)return -1;
        clock++;
        auto itr = keyTable.find(key);
        if (itr == keyTable.end())return -1;
        cacheInfo old_info = itr->second;
        cacheInfo new_info(key,old_info.val, old_info.fre+1,clock);
        keyTable[key] = new_info;
        cacheInfoTable.erase(old_info);
        cacheInfoTable.insert(new_info);
        return old_info.val;
    }

    void put(int key, int value) {
        if (cap == 0)return;
        clock++;
        auto itr = keyTable.find(key);
        if (itr != keyTable.end()) {
            cacheInfo old_info = itr->second;
            cacheInfo new_info(key, value, old_info.fre + 1, clock);
            keyTable[key] = new_info;
            cacheInfoTable.erase(old_info);
            cacheInfoTable.insert(new_info);
            return;
        }
        if (now_size == cap) {
            removeLast();
        }
        else {
            now_size++;
        }

     
            cacheInfo new_info(key, value, 1, clock);
            keyTable[key] = new_info;
            cacheInfoTable.insert(new_info);
       
     
    }
};