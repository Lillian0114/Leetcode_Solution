using namespace std;
#include <vector>
#include <iostream>

/*法三 : 符合題目要求 : 除了自己以外，左邊乘起來 × 右邊乘起來
*/
class Solution {
public: 
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        int left = 1;
        for (int i = 0; i < nums.size(); i++) {
            result[i] = left;
            left *= nums[i];
        }
        int right = 1;
        for (int i = nums.size()-1; i >=0; i--) {
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }
};

int main () {
    std::vector<int> nums = {5, 4, 3, 2};
    std::vector<int> ans;
    Solution sol;
    ans = sol.productExceptSelf(nums);
    for(auto num : ans) {
        std::cout << num << ",";
    }
}

/* 法一: 不符合題目要求，時間複雜度 : O(n^2)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            int perNum = 1;
            for(int j = 0; j < nums.size(); j++) {
                if(i != j){
                    perNum*=nums[j];
                }
            }
            result.push_back(perNum);
        }
        return result;
    }
};
*/

/*法二: 有用除法，也不符合題目要求，時間複雜度 : O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        int product = 1;
        int zeroCount = 0;

        // 先計算非 0 元素的乘積，並統計 0 的數量
        for (int num : nums) {
            if (num == 0) {
                zeroCount++;
            } else {
                product *= num;
            }
        }

        // 根據 zeroCount 決定結果
        if (zeroCount > 1) {
            // 超過一個 0，全部都是 0
            return result;
        }

        for (int i = 0; i < n; i++) {
            if (zeroCount == 0) {
                result[i] = product / nums[i];
            } else {
                // 有一個 0，只在該位置放 product，其餘為 0
                if (nums[i] == 0) {
                    result[i] = product;
                } else {
                    result[i] = 0;
                }
            }
        }

        return result;
    }
};
*/