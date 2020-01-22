//LeetCode 445. Add Two Numbers II
#include "mainHeader.h"
#include <iostream>
using namespace std;

 
void to_str(string&a,ListNode* l1) {
    if (l1->next == nullptr) {
        a.push_back(l1->val + '0');
        return;
    }
    a.push_back(l1->val + '0');
    to_str(a,l1->next);
}
ListNode* to_list(string& a,int pos) {
    if (pos==a.size()-1) {
      return new ListNode(a[pos] -'0');
    }
   
    ListNode* ans = new ListNode(a[pos] - '0');
    ListNode* tail = to_list(a,pos+1);
    ans->next = tail;
    return ans;
}
void appendZero(string& a, int n){

for (int i = 0; i < n; i++) {
    a.push_back('0');
}

}
string addStr(string&a ,string& b) {
    string ans; int up = 0;
   
    int len = a.size();
    for (int i = 0; i < len; i++) {
        int sum = a[i] - '0' + b[i] - '0' + up;
        up = sum / 10;
        ans.push_back(sum % 10 + '0');
    }
    if(up) ans.push_back('1');
    return ans;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1->val == 0)return l2;
    if (l2->val == 0)return l1;
    string s1; to_str(s1,l1);
    string s2; to_str(s2,l2);
    reverse(s1.begin(), s1.end()); reverse(s2.begin(), s2.end());
    if (s1.size() > s2.size()) {
        appendZero(s2, s1.size() - s2.size());
    }
    else {
        appendZero(s1, s2.size() - s1.size());
    }
    string sum = addStr(s1, s2);
    reverse(sum.begin(), sum.end());
    return to_list(sum,0);
}