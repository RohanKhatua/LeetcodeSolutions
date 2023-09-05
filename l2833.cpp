#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int furthestDistanceFromOrigin(string moves)
    {
        int rcnt = 0;
        int lcnt = 0;
        int dcnt = 0;

        for (char mv : moves) {
            if (mv=='R') rcnt++;
            else if (mv=='L') lcnt++;
            else dcnt++;
        }

        if (rcnt>lcnt) {
            return rcnt-lcnt+dcnt;
        }
        else if (rcnt<lcnt) {
            return lcnt-rcnt+dcnt;
        }
        else {
            return dcnt;
        }
    }
};
