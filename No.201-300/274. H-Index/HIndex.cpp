using namespace std;
#include <vector>
#include <iostream>

class Solution{
public:
    int hIndex(vector<int>& citations){
        int n = citations.size();
        std::vector<int> bucket(n+1, 0);
        for(int c: citations) {
            if (c >= n+1) {
                bucket[n]++;
            } else {
                bucket[c]++;
            }
        }

        int h = 0;
        for(int i = n; i >= 0; i--) {
            h += bucket[i];
            if (h >= i) {
                return i;
            }
        }
        return 0;
    }
};

int main() {
    std::vector<int> nums = {3,0,6,1,5};
    Solution sol;
    int ans = sol.hIndex(nums);
    std::cout << ans;
}