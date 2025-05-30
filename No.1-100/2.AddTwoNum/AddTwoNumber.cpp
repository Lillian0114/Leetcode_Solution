using namespace std;
#include <iostream>
#include <iostream>
#include <vector>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummy = new ListNode();
            ListNode* res = dummy;
            int total = 0, carry = 0;
            while (l1 || l2 || carry) {
                total = carry;
                if (l1) {
                    total += l1->val;
                    l1 = l1->next;
                }
                if (l2) {
                    total += l2->val;
                    l2 = l2->next;
                }
                int num = total % 10;
                carry = total/10;
                dummy->next = new ListNode(num);
                dummy = dummy->next;
            }

            ListNode* result = res->next;
            delete res;
            return result;
        }
};


// 將 vector 轉成 linked list
ListNode* vectorToList(const vector<int>& nums) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int n : nums) {
        current->next = new ListNode(n);
        current = current->next;
    }
    ListNode* result = dummy->next;
    delete dummy;
    return result;
}

// 印出 linked list
void printList(ListNode* node) {
    while (node) {
        cout << node->val;
        if (node->next) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> nums1 = {2, 4, 3};
    vector<int> nums2 = {5, 6, 4};
    ListNode* l1 = vectorToList(nums1);
    ListNode* l2 = vectorToList(nums2);

    ListNode* result = sol.addTwoNumbers(l1, l2);

    printList(result);  // 正確輸出：7 -> 0 -> 8

    return 0;
}