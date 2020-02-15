//457. Circular Array Loop

#include "mainHeader.h" 
#include<unordered_set>
 using namespace std;
 int getPos(int n, int size) {
     if (n >= 0)return n % size;
     int div = -1 * n / size;
     return n + size * (div + 1);
 }

 bool DFS(const vector<int>& nums, vector<bool>& isVisited, unordered_set<int>& visited, int now_pos, bool isPostive) {
     if (visited.find(now_pos) != visited.end())return true;
     if (isVisited[now_pos])return false;
     if (isPostive) {
         if (nums[now_pos] < 0)return false;
     }
     else {
         if (nums[now_pos] > 0)return false;
     }
     visited.insert(now_pos);
     isVisited[now_pos] = true;
     int next = getPos(now_pos + nums[now_pos], nums.size());
     if (next == now_pos)return false;
     return DFS(nums, isVisited, visited, next, isPostive);
 }

bool circularArrayLoop(std::vector<int>& nums) {
    if (nums.size() < 2)return false;
    vector<bool>isVisited;  isVisited.resize(nums.size());
    for (int i = 0; i < isVisited.size(); i++)isVisited[i] = false;
    for (int i = 0; i < nums.size(); i++) {
        unordered_set<int> visited;
        if (DFS(nums, isVisited, visited, i, nums[i] > 0))return true;
    }
    return false;
}