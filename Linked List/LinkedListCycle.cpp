// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//    // FLOYDS CYCLE ALGORITHM USE 2 POINTER APPROACH ONE SLOW POINTER AND ONE FAST POINTER
//    if(head==NULL)
//    return false;
//    ListNode* fast=head->next;
//    ListNode* slow=head;
//    while(fast!=NULL && fast!=slow)
//    {
//        fast=fast->next ;
//        if(fast!=NULL)
//        fast=fast->next;
//        slow=slow->next;
//    }
//    if(fast==slow)------------------------------FLOYDS CYCLE ALGORITHM TO DETECT LOOPS
//    return true;
//    else
//    return false;


//     }
// };