#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        
        // Step 1: Split the linked list into two halves
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *secondHalf = slow->next;
        slow->next = nullptr; // Splitting the list
        
        // Step 2: Reverse the second half of the linked list
        ListNode *prev = nullptr, *curr = secondHalf, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        secondHalf = prev;
        
        // Step 3: Merge the two halves by interweaving the nodes alternately
        ListNode *firstHalf = head;
        while (secondHalf) {
            ListNode *temp1 = firstHalf->next;
            ListNode *temp2 = secondHalf->next;
            firstHalf->next = secondHalf;
            secondHalf->next = temp1;
            firstHalf = temp1;
            secondHalf = temp2;
        }
    }
};

// Function to print the linked list
void printList(ListNode *head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    Solution().reorderList(head1);
    printList(head1); // Output: 1 4 2 3

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    Solution().reorderList(head2);
    printList(head2); // Output: 1 5 2 4 3

    return 0;
}
