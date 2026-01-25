using namespace std;
# include <iostream>
# include <climits>

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long long ans = 0;

        // skip leading spaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        // sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < s.size() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            if (sign == 1 && ans > INT_MAX) return INT_MAX;
            if (sign == -1 && -ans < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * ans;
    }
};

int main() {
    Solution sol;
    cout << sol.myAtoi("1337c0d3");
}