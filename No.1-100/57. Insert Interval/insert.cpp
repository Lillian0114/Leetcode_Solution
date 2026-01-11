using namespace std;
#include <vector>
#include <iostream>
#include <algorithm>

// 法二 : 不用排序，時間複雜度較佳
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int n = intervals.size();
    int i = 0;
    while(i < n && intervals[i][1] < newInterval[0]) {
        result.emplace_back(intervals[i++]);
    }

    while(i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.emplace_back(newInterval);

    while(i < n) {
        result.emplace_back(intervals[i++]);
    }
    return result;
}

// 法一 : 用了 sort(), 所以時間複雜度較差
vector<vector<int>> worseInsert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.emplace_back(newInterval);
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> result;
    result.emplace_back(intervals[0]);
    
    for(int i = 1; i < intervals.size(); ++i) {
        if(result.back()[1] >= intervals[i][0]) {
            result.back()[1] = max(result.back()[1], intervals[i][1]); 
        } else {
            result.emplace_back(intervals[i]);
        }
    }
    return result;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    vector<vector<int>> mergedIntervals = insert(intervals, newInterval);
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    cout << "Using worse method:" << endl;
    vector<vector<int>> worseMergedIntervals = worseInsert(intervals, newInterval);
    for(const auto& interval : worseMergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
}