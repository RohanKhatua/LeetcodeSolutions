#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        // string a = "abcdefghijklmnopqrstuvwxyza";
        vector<pair<char, char>> want;
        for (int i=0;i<str2.length();i++) {
            if (str2[i]=='a') {
                want.push_back(make_pair('a', 'z'));
            }
            else
                want.push_back(make_pair(char(str2[i]), char(str2[i]-1)));
        }


        int curr_index = 0;
        int str_index = 0;
        while (curr_index<want.size() && str_index<str1.length()) {
            if (str1[str_index] == want[curr_index].first || str1[str_index] == want[curr_index].second) {
                curr_index++;
            }
            str_index++;
        }

        if (curr_index==want.size()) {
            return true;
        }

        else return false;
    }
};


int main() {
    Solution s;
    cout<<s.canMakeSubsequence("abc", "ad");
}
