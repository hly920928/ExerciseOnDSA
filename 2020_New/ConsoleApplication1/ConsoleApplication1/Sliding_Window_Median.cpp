//480. Sliding Window Median
#include "mainHeader.h"
#include <set>
 
using namespace std;
void eraseLast(multiset<int>& table,int val) {
	auto itr = table.upper_bound(val);
	itr--;
	table.erase(itr);
}
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
				median--;
				eraseLast(table, deletedElement);
				if ( insertedElement>m) median++;
				else if (insertedElement<m) goto OUT;
			
		 
			}
		}
		else if(deletedElement > m) {
			table.insert(insertedElement);
			eraseLast(table, deletedElement);
			if (insertedElement >= m)goto OUT;
		    if (insertedElement < m) median--;
		}
		else if (deletedElement <m ) {
			table.insert(insertedElement);
			eraseLast(table, deletedElement);
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
	ans.push_back(((double)*median_1 + (double)*median_2) / 2);
	for (int i = 1; i + k <= nums.size(); i++) {
		int  deletedElement = nums[i - 1];
		int  insertedElement = nums[i + k - 1];
		int m1 = *median_1;
		int m2 = *median_2;
		if (k == 2) {
			ans.push_back(((double)nums[i] + (double)nums[i+1]) / 2);
			continue;
		}
		//TODO change median according to relation between median_1,median_2,deletedElement,insertedElement
		if (deletedElement==m1|| deletedElement == m2) {
			if (deletedElement == m1 && deletedElement == m2) {
				if (insertedElement < m1) {
					table.insert(insertedElement);
					median_1--;
					median_2--;
					eraseLast(table, deletedElement);
				}
				else if (insertedElement >=m1) {
					median_1--;
					median_2--;
					table.insert(insertedElement);
					eraseLast(table, deletedElement);
					median_1++;
					median_2++;
				}
			}
			else if (deletedElement == m1) {
				if (insertedElement < m2) {
					table.insert(insertedElement);
					eraseLast(table, deletedElement);
					median_1 = median_2; median_1--;
	
				}
				else if (insertedElement >= m2) {
					table.insert(insertedElement);	
					median_1++;
					median_2++;
					eraseLast(table, deletedElement);
				}
			}
			else if (deletedElement == m2) {
				if (insertedElement < m1) {
					table.insert(insertedElement);
					median_1--;
					median_2--;
					eraseLast(table, deletedElement);
				}
				else if (insertedElement >= m1) {
					table.insert(insertedElement);
					eraseLast(table, deletedElement);
					median_2 = median_1; median_2++;
				
				}
			}
		}
		else if (deletedElement > m2) {
			if(insertedElement>=m2){
				eraseLast(table, deletedElement);
				table.insert(insertedElement);
				 
			}
			else if(insertedElement< m2&& insertedElement >=m1) {
				eraseLast(table, deletedElement);
				table.insert(insertedElement);
				median_2--;
			}
			else if( insertedElement < m1) {
				eraseLast(table, deletedElement);
				table.insert(insertedElement);
				median_1--;
				median_2--;
			}
		}
		else if (deletedElement <m1) {
			if (insertedElement >= m2) {
				eraseLast(table, deletedElement);
				table.insert(insertedElement);
				median_1++;
				median_2++;
			}
			else if (insertedElement < m2 && insertedElement >= m1) {
				eraseLast(table, deletedElement);
				table.insert(insertedElement);
				median_1++;
			}
			else if (insertedElement < m1) {
				eraseLast(table, deletedElement);
				table.insert(insertedElement);
			}
		}
		//
		OUT:
		ans.push_back(((double)*median_1 + (double)*median_2) / 2);
		//eraseLast(table, deletedElement);
		//table.insert(insertedElement);
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
