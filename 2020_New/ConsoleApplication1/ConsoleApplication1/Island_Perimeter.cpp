//463. Island Perimeter
#include "mainHeader.h"
 
using namespace std;

int get(const vector<vector<int>>& grid, int x, int y) {
	if (x < 0 || x >= grid.size())return 1;
	if (y < 0 || y >= grid[0].size())return 1;
	return grid[x][y]==1?0:1;
}
int islandPerimeter(vector<vector<int>>& grid) {
	if (grid.size() == 0)return 0;
	if (grid[0].size() == 0)return 0;
	int l = grid.size(); int w = grid[0].size();
	int ans=0;
	for (int x = 0; x < l; x++) {
		for (int y = 0; y <w; y++) {        
			if (grid[x][y] == 1) {
				ans += get(grid, x - 1, y);
				ans += get(grid, x + 1, y);
				ans += get(grid, x, y+1);
				ans += get(grid, x, y-1);
			}
		}
	}
	return ans;
}