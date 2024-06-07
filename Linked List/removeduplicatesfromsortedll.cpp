
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

// Example 1:


// Input: head = [1,1,2]
// Output: [1,2]
// Example 2:


// Input: head = [1,1,2,3,3]
// Output: [1,2,3]
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
        return head;
        ListNode* curr=head;
        ListNode* next=head->next;
        while(next!=NULL)
        {
            if(curr->val==next->val)
            {
                next=next->next;
                curr->next=next;
            }
            else
            {
                curr=curr->next;
                next=next->next;
            }
        }
        return head;
    }
};