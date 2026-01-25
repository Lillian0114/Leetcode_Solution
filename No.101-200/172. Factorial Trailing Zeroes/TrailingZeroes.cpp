using namespace std;
# include <iostream>

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        while(n > 0) {
            n /= 5;
            result += n;
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.trailingZeroes(25);
}