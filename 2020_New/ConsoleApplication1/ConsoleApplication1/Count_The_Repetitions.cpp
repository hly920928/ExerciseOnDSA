//466. Count The Repetitions
#include "mainHeader.h"
#include <unordered_set>

using namespace std;
 
int getMaxRepetitions(string s1, int n1, string s2, int n2) {
	if (n1 == 0)return 0;
    int t1[26];   int t2[26];
    for (int i = 0; i < 26; i++) {
        t1[i]=0;  t2[i] = 0;
    }
    for (auto c : s1)t1[c - 'a']++;
    for (auto c : s2)t2[c - 'a']++;
    for (int i = 0; i < 26; i++) {
        if (t1[i] == 0 && t2[i] != 0)return 0;
        if (s2.size() == 1) {
            if (t2[i] != 0)return t1[i] * n1 / n2;
        }
    }
    unsigned int s1_len = s1.size(); unsigned int s2_len = s2.size();
    unsigned int s1_total = s1_len * n1;
    unsigned int s1_pos = 0; unsigned int s2_pos = 0;
    unsigned int s2_count = 0;
     int firstTailerMatchPos=-1;
    while (s1_pos < s1_total) { 
        if (s1[s1_pos % s1_len] == s2[s2_pos % s2_len]) {
            if (s2_pos % s2_len == s2_len - 1) {
                s2_count++;
                if (firstTailerMatchPos == -1) {
                    firstTailerMatchPos = s1_pos;
                }
                else if (s1_pos % s1_len == firstTailerMatchPos % s1_len) {
                    //find repeating circle,leap forward
                    unsigned int s1_step = s1_pos - firstTailerMatchPos;
                    unsigned int s2_step = s2_pos - (s2_len - 1);
                    unsigned int s2_unit_count = s2_count - 1;
                    unsigned int round = (s1_total - (firstTailerMatchPos + 1)) / s1_step;
                    s2_count = s2_count - s2_unit_count + s2_unit_count * round;  
                    s1_pos = firstTailerMatchPos + round * s1_step + 1;
                    s2_pos= s2_len - 1+ round * s2_step + 1;
                    continue;
                }
            }
            s1_pos++;
            s2_pos++;
        }
        else {
            s1_pos++;
        }
    }
    return s2_count / n2;
}