#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<char,int> freq;
    bool canConstruct(string ransomNote, string magazine) {
        for (char ch : ransomNote) {
            freq[ch]--;
        }
        for (char ch : magazine) {
            freq[ch]++;
        }
        for (auto pr:freq) {
            if (pr.second<0) return false;
        }
        return true;
    }
};
