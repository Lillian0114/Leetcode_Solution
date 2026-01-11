using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3) {
            return result;
        }

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                int total = nums[i] + nums[j] + nums[k];
                if(total > 0) {
                    k--;
                } else if (total < 0) {
                    j++;
                } else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(nums[j] == nums[j-1] && j < k) {
                        j++;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> result;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    result = sol.threeSum(nums);
    for (auto& v : result) {
        cout << "[ ";
        for (int x : v) cout << x << ", ";
        cout << "]\n";
    }
}