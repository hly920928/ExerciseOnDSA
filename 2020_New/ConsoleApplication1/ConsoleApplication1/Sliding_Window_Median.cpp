//480. Sliding Window Median
#include "mainHeader.h"
#include <set>
 
using namespace std;
void medianSlidingWindowOdd(vector<int>& nums, int k, vector<double>& ans) {
	multiset<int> table;
	for (int i = 0; i < k; i++) table.insert(nums[i]);
	auto median = table.begin();
	for (int i = 0; i < (k - 1) / 2; i++)median++;
	ans.push_back(*median);
	for (int i = 1; i + k <= nums.size(); i++) {
		int  deletedElement = nums[i - 1];
		int  insertedElement = nums[i + k - 1];
		int m = *median;
		//TODO change median according to relation between median,deletedElement,insertedElement
		if (deletedElement ==m) {
			if (insertedElement == m)goto OUT;
			if (insertedElement != m) {	
				table.insert(insertedElement);
				if ( insertedElement>m) median++;
				else if (insertedElement<m) median--;
				table.erase(deletedElement);
			}
		}
		else if(deletedElement > m) {
			table.insert(insertedElement);
			table.erase(deletedElement);
			if (insertedElement >= m)goto OUT;
		    if (insertedElement < m) median--;
		}
		else if (deletedElement <m ) {
			table.insert(insertedElement);
			table.erase(deletedElement);
			if (insertedElement< m) goto OUT;
			if (insertedElement >= m) median++;
			}
 
	 OUT:
 
		ans.push_back(*median);
	}
}
void medianSlidingWindowEven(vector<int>& nums, int k, vector<double>& ans) {
	multiset<int> table;
	for (int i = 0; i < k; i++) table.insert(nums[i]);
	auto median_1 = table.begin();
	auto median_2 = median_1; median_2++;
	for (int i = 0; i < (k - 1) / 2; i++) {
		median_1++; median_2++;
	}
	ans.push_back((*median_1+ *median_2)/2);
	for (int i = 1; i + k <= nums.size(); i++) {
		int  deletedElement = nums[i - 1];
		int  insertedElement = nums[i + k - 1];
		int m1 = *median_1;
		int m2 = *median_2;
		//TODO change median according to relation between median_1,median_2,deletedElement,insertedElement
		if (deletedElement==m1|| deletedElement == m2) {

		}
		else if(deletedElement>m1&& deletedElement < m2){

		}
		else if (deletedElement > m2) {

		}
		else if (deletedElement <m1) {

		}
		//
		ans.push_back(((double)*median_1 + (double)*median_2) / 2);
		table.erase(deletedElement);
		table.insert(insertedElement);
	}
}
vector<double> medianSlidingWindow(vector<int>& nums, int k) {
	vector<double> ans;
	if (k % 2 == 1) {
		medianSlidingWindowOdd(nums,k, ans);
	}
	else {
		medianSlidingWindowEven(nums, k, ans);
	}
	return ans;
}
