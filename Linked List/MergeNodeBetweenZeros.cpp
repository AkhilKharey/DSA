// https://leetcode.com/problems/merge-nodes-in-between-zeros/
// You are given the head of a linked list, which contains a series of integers 
// separated by 0's. The beginning and end of the linked list will have Node.val == 0.

// For every two consecutive 0's, merge all the nodes lying in between 
// them into a single node whose value is the sum of all the merged nodes. 
// The modified list should not contain any 0's.

// Return the head of the modified linked list.

 

// Example 1:


// Input: head = [0,3,1,0,4,5,2,0]
// Output: [4,11]
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        if(!head) return NULL;
        if(head->next==NULL) return NULL;
        while(temp && temp->val==0) temp=temp->next;
        if(temp==NULL)return NULL;
        ListNode* head2= new ListNode(temp->val);
        ListNode* temp2=head2;
        temp=temp->next;
        while(temp)
        {
            if(temp->val!=0) temp2->val+=temp->val;
            else if(temp->val==0)
            {
              while(temp && temp->val==0) temp=temp->next;
              if(!temp) break;
              temp2->next=new ListNode(temp->val);
              temp2=temp2->next;
            }
            temp=temp->next;
        }
        return head2;
    }
};