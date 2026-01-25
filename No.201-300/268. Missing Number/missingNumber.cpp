using namespace std;
# include <iostream>
# include <vector>

class Solution {
public:
    int missingNumber(vector<int> nums) {
        int n = nums.size();
        int total = n * (n+1) / 2;
        for(int i = 0; i < n; i++) {
            total -= nums[i];
        }
        return total;
    }
};

int main() {
    Solution sol;
    cout << sol.missingNumber({9,6,4,2,3,5,7,0,1});
}