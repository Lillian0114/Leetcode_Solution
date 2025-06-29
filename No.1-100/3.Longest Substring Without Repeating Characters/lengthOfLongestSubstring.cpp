using namespace std;
#include <iostream>
#include <iostream>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0, right = 0, maxLength = 0;
        while (right < s.size()) {
            if (charSet.find(s[right]) == charSet.end()) {
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            } else {
                charSet.erase(s[left]);
                left++;
            }
        }
        return maxLength;
    }
};

int main() {
    Solution solution;
    string input = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}