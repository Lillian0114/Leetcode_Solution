using namespace std;
#include <iostream>

class Solution {
    public:
        string convertToTitle(int columnNumber) {
            string result = "";
            
            while(columnNumber > 0) {
                columnNumber --;
                result = char((columnNumber % 26) + 'A') + result;
                columnNumber /= 26;
            }
            
            return result;
        }
    };

int main() {
    // std::vector<int> nums = {1,2,3,4};
    int nums = 28;
    Solution sol;
    std::cout << sol.convertToTitle(nums) << std::endl;
    return 0;
}