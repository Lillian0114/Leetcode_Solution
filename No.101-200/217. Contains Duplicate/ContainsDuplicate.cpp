using namespace std;
#include <vector>
#include <iostream>
#include <unordered_set>

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> seen;
            for(int num: nums){
                if(seen.count(num) > 0)
                    return true;
                seen.insert(num);
            }
            return false;
        }
    };


int main() {
    // std::vector<int> nums = {1,2,3,4};
    std::vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    Solution sol;
    std::cout << sol.containsDuplicate(nums) << std::endl;
    return 0;
}