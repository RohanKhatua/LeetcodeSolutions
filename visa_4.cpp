#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;
    res.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        if (res.back()[1] >= intervals[i][0])
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        else
            res.push_back(intervals[i]);
    }

    return res;
}

vector<int> findNumBytes(vector<vector<int>> chunks)
{
    vector<int> res;

    vector<vector<int>> intervals;

    intervals.push_back(chunks[0]);
    res.push_back(chunks[0][1] - chunks[0][0] + 1);

    for (int i = 1; i < chunks.size(); i++)
    {

        bool inserted = false;
        for (int j = 0; j < intervals.size(); j++)
        {
            if (chunks[i][0] <= intervals[j][0])
            {
                intervals.insert(intervals.begin() + j, chunks[i]);
                inserted = true;
                break;
            }
        }
        if (!inserted)
        {
            intervals.insert(intervals.end(), chunks[i]);
        }
        intervals = merge(intervals);

        int count = 0;
        for (auto interval : intervals)
        {
            count += interval[1] - interval[0] + 1;
        }

        res.push_back(count);
    }

    return res;
}

int main()
{
    vector<vector<int>> v = {{7, 9}, {1, 3}, {8, 15}, {6, 9}, {2, 4}};
    vector<int> res = findNumBytes(v);
    for (int r : res)
    {
        cout << r << "\t";
    }
}
