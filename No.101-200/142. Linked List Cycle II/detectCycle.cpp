#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* detectCycle(ListNode* head) {
            ListNode* fast = head;
            ListNode* slow = head;
            bool hasCycle = false;
            while (fast != nullptr && fast->next != nullptr) {
                fast = fast->next->next;
                slow = slow->next;

                if (fast == slow) {
                    hasCycle = true;
                    break;
                }
            }
            if (!hasCycle)
                return nullptr;
            
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // The start of the cycle
        }
};

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Create a cycle

    Solution sol;
    ListNode* cycleStart = sol.detectCycle(head);
    if (cycleStart) {
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected" << endl;
    }
    
}