//466. Count The Repetitions
#include "mainHeader.h"
using namespace std;
vector<int> constructRectangle(int area) {

	int ans = sqrt(area);
 
	while (true) {
		if (area % ans == 0) {
			return vector<int>({ area / ans ,ans });
		}
		ans--;
	}
}
