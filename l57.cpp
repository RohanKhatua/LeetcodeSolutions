#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool overlap(vector<int> in1, vector<int> in2) {
        if (in1[1]>=in2[0]) return true;
        else return false;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size()==0) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        //place then merge
        int index;
        if (newInterval[0]<intervals[0][0]) {
            index = 0;
        }
        else {
            for (int i=1;i<intervals.size();i++) {
                if (newInterval[0]>=intervals[i-1][0] && newInterval[0]<=intervals[i][0]) {
                    index = i;
                    break;
                }
            }
        }

        intervals.insert(intervals.begin()+index, newInterval);

        int overlap_start;
        if (index ==0) {
            overlap_start = 0;
        }
        else {
            if (overlap(intervals[index-1], intervals[index])){
                overlap_start = index - 1;                
            }
            else overlap_start = index;
        }

        int overlap_end = index;
        int current_index = index+1;
        while (current_index<intervals.size()) {
            if (overlap(newInterval, intervals[current_index])) {
                overlap_end = current_index;
                current_index++;
            }
            else break;
        }

        int rem = overlap_end-overlap_start+1;
        auto it = intervals.begin() + overlap_start;
        int time_start = intervals[overlap_start][0];
        int time_end = 0;
        for (int i=overlap_start;i<=overlap_end;i++) {
            time_end = max(time_end, intervals[i][1]);
        }

        while (rem--&&it!=intervals.end()) {
            intervals.erase(it);
        }

        intervals.insert(intervals.begin()+overlap_start, {time_start, time_end});

        for (auto interval : intervals) {
            cout<<interval[0]<<","<<interval[1]<<"\t";
        }

        cout<<"Overlap Start = "<<overlap_start<<endl;
        cout<<"Overlap End = "<<overlap_end<<endl;

        return intervals;

    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals = {{0,4},{7,12}};
    vector<int> newi = {0,5};
    s.insert(intervals, newi);
}
