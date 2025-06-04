
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode* fast = head;
            ListNode* slow = head;
            
            while (fast != nullptr && fast->next != nullptr) {
                fast = fast->next->next;
                slow = slow->next;
                
                if(fast == slow) 
                    return true;
            }
            return false;
        }
    };

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Create a cycle

    Solution sol;
    sol.hasCycle(head) ? std::cout << "Cycle detected" : std::cout << "No cycle detected";
    std::cout << std::endl;
}