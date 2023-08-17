#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<int> pos;
        vector<int> neg;
        vector<vector<int>> ans;

        // size 3 array

        if (nums.size() == 3)
        {
            if (accumulate(nums.begin(), nums.end(), 0) == 0)
            {
                ans.push_back(nums);
                return ans;
            }
        }

        int zero = 0;
        for (int num : nums)
        {
            if (num > 0)
            {
                pos.push_back(num);
            }
            else if (num == 0)
            {
                zero++;
            }
            else
            {
                neg.push_back(num);
            }
        }

        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());

        if (zero > 0)
        {
            int pt1 = pos.size() - 1;
            int pt2 = 0;

            while (pt1 >= 0 && pt2 < neg.size())
            {

                if (pos[pt1] == abs(neg[pt2]))
                {
                    ans.push_back({pos[pt1], neg[pt2], 0});
                    pt1--;
                    pt2++;
                }

                if (pos[pt1] > abs(neg[pt2]))
                {
                    pt1--;
                }

                else
                {
                    pt2++;
                }
            }
        }

        // now to generate triplets which do not involve a 0
        // we get 2 positive numbers and 1 neg number or 1 positive and 2 neg

        // if only one -ve number -> we can only do 2 +ve 1 -ve

        if (neg.size() > 1)
        {
            int pt1 = 0;
            int pt2 = neg.size() - 1;
            for (int num : pos)
            {
                while (pt1 < neg.size() && pt2 >= 0 && pt1 != pt2)
                {
                    int val = num + neg[pt1] + neg[pt2];
                    if (val == 0)
                    {
                        ans.push_back({num, neg[pt1], neg[pt2]});
                        pt1++;
                        pt2--;
                    }
                    else if (val < 0)
                    {
                        pt1++;
                    }
                    else
                    {
                        pt2--;
                    }
                }
            }
        }

        if (pos.size() > 1)
        {

            int pt1 = 0;
            int pt2 = pos.size() - 1;
            for (int num : neg)
            {
                while (pt1 < pos.size() && pt2 >= 0 && pt1 != pt2)
                {
                    int val = num + pos[pt1] + pos[pt2];
                    if (val == 0)
                    {
                        ans.push_back({num, pos[pt1], pos[pt2]});
                        pt1++;
                        pt2--;
                    }
                    else if (val < 0)
                    {
                        pt1++;
                    }
                    else
                    {
                        pt2--;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> triplets = s.threeSum(v);
    for (auto triplet : triplets)
    {
        for (auto ele : triplet)
        {
            cout << ele << "\t";
        }
        cout << endl;
    }
}

// order doesnt matter
// to add up to 0 we must either add 3 0s or 2 +ve and 1 -ve or 1 +ve and 2 negative or one 0 and 1 +ve and 1 -ve
// if we sort the array
// large positive numbers in the end
// large negative numbers in the beginning
// unless the array is only 0 must have both +ve and negative numbers
// may or may not have required triplet

// divide the array into +ve and negative part
// count zeroes
// question? is sorting two smaller arrays faster than sorting one big array
