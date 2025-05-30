#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private: 
        int sumDigits(int n) {
            int sum = 0;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
            return sum;
        }

    public:
        int smallestIndex(vector<int>& nums) {
            for (int i = 0; i< nums.size(); i++) {
                if (i == sumDigits(nums[i])) {
                    return i;
                }
            }
            return -1; 
        }
    };