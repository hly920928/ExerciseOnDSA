//LeetCode 452. Minimum Number of Arrows to Burst Balloons
#include "mainHeader.h"
#include <algorithm>

using namespace std;
bool isSmaller(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];

}
int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() == 0)return 0;
    sort(points.begin(), points.end(), isSmaller);
    int ans = 0; int minRight = points[0][1];
    for (int i = 1; i < points.size(); i++) {
        auto& now = points[i];
        if (now[0] > minRight) {
            ans++;
            minRight = now[1];

        }
        else {
            minRight = min(minRight, now[1]);

        }


    }

    return ans + 1;
}