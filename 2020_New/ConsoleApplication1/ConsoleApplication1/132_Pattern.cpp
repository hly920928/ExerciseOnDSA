// 456. 132 Pattern
#include "mainHeader.h"
#include <stack>
using namespace std;

bool find132pattern(vector<int>& nums) {
    if (nums.size() < 3)return false;
    int cur_max_s3 = INT_MIN;
    stack<int>cur_max_s3_candidate;
    int last = nums.size() - 1;
    if (nums[last] < nums[last - 1]) {
        cur_max_s3 = nums[last];
        cur_max_s3_candidate.push(nums[last - 1]);
        last = last - 2;
    }
    else {
        cur_max_s3_candidate.push(nums[last]);
        cur_max_s3_candidate.push(nums[last-1]);
        last = last - 2;
    }
    for (int i = last; i >= 0; i--) {
        if (cur_max_s3 != INT_MIN && cur_max_s3 > nums[i])return true;
        if (cur_max_s3 <nums[i]) {
            while (!cur_max_s3_candidate.empty()) {
                if (cur_max_s3_candidate.top() >= nums[i])break;
                cur_max_s3 = max(cur_max_s3, cur_max_s3_candidate.top());
                cur_max_s3_candidate.pop();
            }
            cur_max_s3_candidate.push(nums[i]);
        }
    }


    return false;
}