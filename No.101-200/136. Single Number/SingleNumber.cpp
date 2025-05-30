using namespace std;
#include <vector>
#include <iostream>

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int ans = 0;
            for (auto x: nums){
                ans ^= x;
            }
            return ans;
        }
    };


int main() {
    std::vector<int> nums = {4, 1, 2, 1, 2};
    Solution sol;
    std::cout << sol.singleNumber(nums) << std::endl;
    return 0;
}