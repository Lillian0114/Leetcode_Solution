using namespace std;
#include <vector>
#include <iostream>

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorResult = 0;
        for(int num : nums) {
            xorResult ^= num;
        }

        int first_group = 0, second_group = 0;
        int first_bit = 0;
        while(((xorResult >> first_bit) & 1) == 0) {
            first_bit++;
        }
        for(int num : nums) {
            if ((num >> first_bit) & 1) {
                first_group ^= num; // �Ĥ@��
            } else {
                second_group ^= num; // �ĤG��
            }
        }
        return {first_group, second_group}; // ��^��Ӱߤ@���Ʀr
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    Solution sol;
    vector<int> result = sol.singleNumber(nums);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}