#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length()==1) return 1;
        // int last = 0;
        int count  = 0;
        int max_count = 0;
        vector<char> curr;
        for (int i=0;i<s.length();i++) {
            if (find(curr.begin(),curr.end(),s[i])==curr.end()) {
                curr.push_back(s[i]);
                count++;
            }
            else {
                max_count = max(max_count, count);
                // int curr_index = i;
                i -=count;
                // last = last+count;
                count = 0;
                curr.clear();
            }
        }
        return max(max_count,count);
        
    }

};

int main() {
    string s = "tmmzuxt";
    Solution o;
    cout<<o.lengthOfLongestSubstring(s);
}