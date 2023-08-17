#include <bits/stdc++.h>
using namespace std;

//sum up all the even frequencies and add 1 if anythung else is availabke

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int ans = 0;
        unordered_map<char, int> freq;
        for (char letter : s) {
            freq[letter]++;
        }
        bool all_even = true;
        for (auto pr : freq) {
            if (pr.second%2!=0) {
                all_even = false;
                if (pr.second>1) {
                    ans+=pr.second-1;
                }
            }
            else if (pr.second!=0) {
                ans+=pr.second;
            }
        }

        if (!all_even) {
            ans+=1;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("abccccdd");
}
