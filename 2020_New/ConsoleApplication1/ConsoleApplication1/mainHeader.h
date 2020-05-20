#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <vector>
#include <cmath>       
#include <math.h>      
#include <random>

#define _USE_MATH_DEFINES
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x = INT_MAX) : val(x), left(NULL), right(NULL) {
    }

};
int threeTupleMinDistance(int a[], int  b[], int  c[], int m, int n, int l);
int minMutation(std::string start, std::string end, std::vector<std::string>& bank);
int countSegments(std::string s);
int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals);
int pathSum(TreeNode* root, int sum);
std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals);
std::vector<int> findAnagrams(std::string s, std::string p);

int findKthNumber(int n, int k);

int arrangeCoins(int n);

std::vector<int> findDuplicates(std::vector<int>& nums);


int compress(std::vector<char>& chars);

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x = -1) : val(x), next(nullptr) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);


int numberOfBoomerangs(std::vector<std::vector<int>>& points);

std::vector<int> findDisappearedNumbers(std::vector<int>& nums);




std::string serialize(TreeNode* root);
TreeNode* deserialize(std::string data);

TreeNode* deleteNode(TreeNode* root, int key);

TreeNode* constructTree(std::vector<int>& v,int i);

std::string frequencySort(std::string s);

int findMinArrowShots(std::vector<std::vector<int>>& points);


int minMoves(std::vector<int>& nums);
int fourSumCount(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D);


int findContentChildren(std::vector<int>& g, std::vector<int>& s);

bool find132pattern(std::vector<int>& nums);

bool circularArrayLoop(std::vector<int>& nums);

int poorPigs(int buckets, int minutesToDie, int minutesToTest);


bool repeatedSubstringPattern(std::string s);


int hammingDistance(int x, int y);


int minMoves2(std::vector<int>& nums);

int islandPerimeter(std::vector<std::vector<int>>& grid);

bool canIWin(int maxChoosableInteger, int desiredTotal);

int getMaxRepetitions(std::string s1, int n1, std::string s2, int n2);

int findSubstringInWraproundString(std::string p);

std::string validIPAddress(std::string IP);

int rand10();

std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words);

bool makesquare(std::vector<int>& nums);

int findMaxForm(std::vector<std::string>& strs, int m, int n);

int findRadius(std::vector<int>& houses, std::vector<int>& heaters);

int findComplement(int num);

int totalHammingDistance(std::vector<int>& nums);

class randPointInCircle {
private:
    double R;
    double cx;
    double cy;
    std::default_random_engine gen;
     std::uniform_real_distribution<double> dist;
public:
    randPointInCircle(double radius, double x_center, double y_center): R(radius), cx(x_center),cy(y_center){
        dist= std::uniform_real_distribution<double>(-1* radius, radius);
    }

    std::vector<double> randPoint() {
        double dx ;    double dy;
        while (true)
        {
            const double x1 = dist(gen);
            const double y1 = dist(gen);
            const double rp2 = std::pow(R, 2.0);

            if (std::pow(x1, 2.0) + std::pow(y1, 2.0) <= rp2)
            {
                dx = x1;   dy = y1;
                break;
            }
        }
        std::vector<double> ans; ans.push_back(cx + dx); ans.push_back(cy + dy);
        return ans;
    }
};

int largestPalindrome(int n);

std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k);

int magicalString(int n);

std::string licenseKeyFormatting(std::string S, int K);

std::string smallestGoodBase(std::string n);

int findMaxConsecutiveOnes(std::vector<int>& nums);

bool PredictTheWinner(std::vector<int>& nums);

int findMinStep(std::string board, std::string hand);

std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums);

std::vector<int> constructRectangle(int area);

int reversePairs(std::vector<int>& nums);

int findTargetSumWays(std::vector<int>& nums, int S);

int findPoisonedDuration(std::vector<int>& timeSeries, int duration);

std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2);

class RectanglesPointPicker {
public:
    std::vector<std::vector<int>>*  rects;
    std::vector<int>areaList;
    std::default_random_engine gen;
    std::uniform_real_distribution<int>rectDist;
    std::uniform_real_distribution<double>inRectDist;
public:
    RectanglesPointPicker(std::vector<std::vector<int>>& rects){
        int areaSum = 0;
        rects =rects;
        for (int i = 0; i < rects.size(); i++) {
            areaSum += area(rects[i]);
            areaList.push_back(areaSum);
        }
        rectDist = uniform_real_distribution<int>(0, areaSum);
        inRectDist= uniform_real_distribution<double>(0, 1.0);
    }

    std::vector<int> pick() {
 
        return pickPointInRect(pickRects());
}
private:
    int pickRects() {
        int areaPos= rectDist(gen);
        if (areaPos == 0)return 0;
        if (areaPos == areaList.back())return areaList.size()-1;
        auto itr = upper_bound(areaList.begin(), areaList.end(), areaPos);
        return itr- areaList.begin(); 
    };
    std::vector<int>  pickPointInRect(int id) {
        auto& r = rects->at(id);
        double xPos = inRectDist(gen);
        double yPos = inRectDist(gen);
        vector<int>ans;
        ans.push_back(r[0] + (r[2] - r[0]) * xPos);
        ans.push_back(r[1] + (r[3] - r[1]) * yPos);
        return ans;
    
    };
    int area(vector<int>&r) {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }
};