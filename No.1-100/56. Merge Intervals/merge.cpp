using namespace std;
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for(const auto& interval: intervals) {
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval); 
            } else {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution sol;
    vector<vector<int>> merged = sol.merge(intervals);
    for (const auto& interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    return 0;
}