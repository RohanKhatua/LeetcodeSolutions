#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t=="") return "";
        unordered_map<char, int> countT, window;

        for (char c : t) {
            countT[c]++;
        }

        int have = 0;
        int need = countT.size();

        vector<int> res = {-1, -1};
        int res_len = INT_MAX;
        int l = 0;

        for (int i =0;i<s.length();i++) {
            char c = s[i];
            window[c] ++;

            bool cInT = t.find(c) != string::npos;

            if (cInT && window[c] == countT[c]) {
                have ++;
            }

            while (have == need) {
                if ((i - l + 1) < res_len) {
                    res = {l, i};
                    res_len = i - l + 1;
                }

                window[s[l]] --; 

                if (window[s[l]] < countT[s[l]]) {
                    have--;
                }

                l++;
            }
        }

        if (res_len!=INT_MAX) {
            return s.substr(l, res_len);
        }

        else return "";
    }
};
