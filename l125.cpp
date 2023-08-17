#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        vector<char> only_letters;
        for (char ch : s) {
            if ((ch>='a' && ch<='z')||(ch>='0' && ch<='9')) {
                only_letters.push_back(ch);
            }
        }
        int n = only_letters.size();
        int half = n/2;
        for (int i=0;i<half;i++) {
            if (only_letters[i] != only_letters[n-i-1]) return false;
        }
        return true;
    }
};



int main (){
    Solution obj;
    string s="A man, a plan, a canal: Panama";
    obj.isPalindrome(s);
}