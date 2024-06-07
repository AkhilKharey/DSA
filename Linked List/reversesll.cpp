// class Solution { -------------------------APPROACH1
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head==NULL||head->next==NULL)
//         {
//             // empty list ho ya single node ki list to reverse krne ka koi fayda nhi
//             return head;
//         }
//         ListNode* prev=NULL;
//         ListNode* curr=head;
//         ListNode* forward=curr->next;

//         while(curr!=NULL)
//         {
//            forward=curr->next;
//            curr->next=prev;
//            prev=curr;
//            curr=forward;
//         }
//         head=prev;
//         return head;
//     }
// };-------------------------------------------------------APPROACH 2 RECURSIVE SOLUTION
//  void reverse(ListNode* &head,ListNode* &curr,ListNode* &prev)
//     {
//       if(curr==NULL)
//       {
//          head=prev;
//          return;
//       }
//       ListNode*forward=curr->next;
//       reverse(head,forward,curr);
//       curr->next=prev;
//     }
