using namespace std;
#include <iostream>
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
           unordered_map<int,int> pairIdx;
           for(int i = 0; i < nums.size(); i++) {
                int num = nums[i];
                if(pairIdx.find(target - num) != pairIdx.end()){
                    return {i, pairIdx[target - num]};
                }
                pairIdx[num] = i;
           } 
           return {};
        }
    };

int main() {
    Solution sol;
    vector<int> nums1 = {2, 7, 11, 5};
    vector<int> result = sol.twoSum(nums1, 9);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}