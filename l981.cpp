#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
public:
    unordered_map<string, map<int, string>> mp;
    unordered_map<string, vector<int>> timestamp_map;

    TimeMap()
    {
        mp = {};
    }

    void set(string key, string value, int timestamp)
    {
        mp[key][timestamp] = value;
        timestamp_map[key].push_back(timestamp);
    }

    string get(string key, int timestamp)
    {
        if (timestamp_map[key].empty())
        {
            return "";
        }

        const vector<int> &timestamps = timestamp_map[key];
        int n = timestamps.size();

        // Handle special cases
        if (timestamp < timestamps.front())
        {
            return "";
        }
        if (timestamp >= timestamps.back())
        {
            return mp[key][timestamps.back()];
        }

        // Binary search to find the index of the largest timestamp less than or equal to the target timestamp
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (timestamps[mid] <= timestamp)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        return mp[key][timestamps[left]];
    }
};


