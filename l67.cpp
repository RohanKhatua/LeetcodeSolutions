#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {

        if (b.length() > a.length())
        {
            string temp = a;
            a = b;
            b = temp;
        }
        int diff = a.length() - b.length();
        string extra = a.substr(0, diff);

        int carry = 0;
        string res = "";
        for (int i = b.length() - 1; i >= 0; i--)
        {
            if (a[i+diff] == '1' && b[i] == '1')
            {
                if (carry == 1)
                {
                    res = "1" + res;
                }
                else
                {
                    res = "0" + res;
                    carry = 1;
                }
            }

            else if (a[i+diff] == '0' && b[i] == '0')
            {
                if (carry == 1)
                {
                    res = "1" + res;
                    carry = 0;
                }

                else
                {
                    res = "0" + res;
                }
            }

            else
            {
                if (carry == 1)
                {
                    res = "0" + res;
                    // carry = 0;
                }

                else
                {
                    res = "1" + res;
                }
            }
        }

        for (int i = extra.length() - 1; i >= 0; i--)
        {
            if (extra[i] == '1' && carry == 1)
            {
                res = "0" + res;
            }
            else if (extra[i] == '0' && carry == 1)
            {
                res = "1" + res;
                carry = 0;
            }
            else
            {
                res = extra[i] + res;
            }
        }

        if (carry == 1)
        {
            res = "1" + res;
        }

        return res;
    }
};

int main()
{
    Solution s;
    cout << s.addBinary("11011", "11");
}
