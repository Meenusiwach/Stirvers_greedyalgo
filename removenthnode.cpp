/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
         if(!head) return nullptr;

        ListNode* p= new ListNode(0);
        p->next=head;
        ListNode* q=p;
        ListNode* r=p;
        for(int i=0;i<n+1;i++){
            q=q->next;
        }
        while(q!=nullptr)
        {
            r=r->next;
            q=q->next;
        }
        ListNode* del=r->next;
        r->next=r->next->next;
        delete del;

         ListNode* newHead = p->next; 
        delete p;
        return newHead;
    }
};
