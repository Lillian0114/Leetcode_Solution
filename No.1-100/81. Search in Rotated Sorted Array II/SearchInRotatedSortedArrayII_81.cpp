#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;
            while(left <= right){
                int mid = left + (right - left)/2;
                if(nums[mid] == target)
                    return true;
                    
                if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                    left += 1;
                    right -= 1;
                } else if(nums[left] <= nums[mid]) {
                        if (nums[left] <= target && target < nums[mid]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                } else {
                        if (nums[mid] < target && target <= nums[right]) {
                        left = mid + 1;
                    } else {
                        right = mid -1;
                    }
                }
            }
            return false;
        }
    };


    
int main() {
    Solution sol;
    vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
    cout << sol.search(nums1, 0) << endl; 
    cout << sol.search(nums1, 3) << endl; 

    vector<int> nums2 = {1, 1, 3, 1};
    cout << sol.search(nums2, 3) << endl; 

    return 0;
}