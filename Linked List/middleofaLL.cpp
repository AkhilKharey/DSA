// // class Solution {
// // public:
// // int getlength(ListNode*  head)
// // {
// //    int len=0;
// //     while(head!=NULL)
// //     {
// //         head=head->next;
// //         len++;
// //     }---------------------------------------------------APPROACH1
// //     return len;
// // }
// //     ListNode* middleNode(ListNode* head) {
// //         int len=getlength(head);
// //         int mid=(len/2);
// //         int cnt=0;
// //         ListNode* temp=head;
// //         while(cnt<mid)
// //         {
// //        temp=temp->next;
// //        cnt++;
// //         }
// //   return temp;
// //     }
// // };
// ListNode* getMiddle(ListNode*&head)
// {
//     if(head==NULL||head->next==NULL)
//     return head;
//     else if(head->next->next==NULL)
//     return head->next;
//     ListNode* fast=head->next;
//     ListNode* slow=head;
//     while(fast!=NULL)
//     {
//         fast=fast->next;
//         if(fast!=NULL)
//         fast=fast->next;----------------------------aAPPROACH2
//         slow=slow->next;
//     }
//     return slow;

// }
// --------------------------------------A3
//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
 private:
     
     Node* getmid(Node* head)
     {
       
         
         Node* slow=head;
         Node* fast=head->next;
         while(fast!=NULL &&fast->next!=NULL )
         {
             fast=fast->next->next;
             slow=slow->next;
         }
         return slow;
     }
     Node* reverse(Node* head)
     {
         if(head==NULL||head->next==NULL)
         return head;
         
         Node* chhotaHead=reverse(head->next);
         head->next->next=head;
         head->next=NULL;
         return chhotaHead;
     }
        
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head==NULL || head->next==NULL)
        return true;
        
        
        // step 1 is to find middle
        Node* mid=getmid(head);
        
        // reverse list after middle part
        Node* temp=mid->next;
        mid->next=reverse(temp);
        // compare both hhalves
        Node* head1=head;
        Node* head2=mid->next;
        while(head2!=NULL)
        {
            if(head1->data!=head2->data)
            return false;
            head1=head1->next;
            head2=head2->next;
        }
        // list ko phle jaisa bana dene ka
        temp=mid->next;
        mid->next=reverse(temp);
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends