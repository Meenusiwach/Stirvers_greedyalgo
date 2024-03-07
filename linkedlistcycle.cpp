#include <iostream>



class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            // If the list is empty or has only one node, there can be no cycle
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (slow != fast) {
            if (!fast || !fast->next) {
                // If fast or fast->next is nullptr, we've reached the end of the list
                return false;
            }

            slow = slow->next;
            fast = fast->next->next;
        }

        // If the while loop exits, it means slow and fast pointers have met, indicating a cycle
        return true;
    }
};

