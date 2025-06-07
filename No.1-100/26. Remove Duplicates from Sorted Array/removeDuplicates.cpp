#include <vector>
#include <iostream>
using std::vector;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.empty()) return 0;
            int left = 1;
            for(int fast = 1; fast < nums.size(); fast++) {
                if (nums[fast] != nums[fast-1]) {
                    nums[left] = nums[fast];
                    left++;
                }
            }
            return left;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int newLength = sol.removeDuplicates(nums);
    
    for (int i = 0; i < newLength; i++) {
        std::cout << nums[i] << " ";
    }
    return 0;
}