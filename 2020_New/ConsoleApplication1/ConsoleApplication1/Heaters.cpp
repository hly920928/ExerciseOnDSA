//475. Heaters
#include "mainHeader.h"
 
using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    int i = 0; int j = 0; int maxR = 0;
    while (true) {
 
        if (i >= houses.size())break;
        if (j == heaters.size()-1) {
            int nowR = abs(houses[i] - heaters[j]);
            maxR = max(maxR, nowR);
            i++;
            continue;
        }
        if (i != 0) {
            if (houses[i] == houses[i - 1]) {
                i++;
                continue;
            }
        }
        int nowR= abs(houses[i] - heaters[j]);
    
        if (nowR == 0) {
            i++;
            continue;
         }
        int nextR= abs(houses[i] - heaters[j+1]);
        if (nextR > nowR) {
            maxR = max(maxR, nowR);
            i++;
        }
        else {
            j++;
        }
    }
    return maxR;
}