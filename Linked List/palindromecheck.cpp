https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
class Solution{
  public:
    //Function to check whether the list is palindrome.N
    Node* getTail(Node* &head)
    {
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        return temp;
    }
    
    Node* reverse(Node* &head)
    {
        if(head==NULL||head->next==NULL)
        return head;
        Node* chhotaHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return chhotaHead;
    }
 
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head==NULL||head->next==NULL)
        return true;
        
        Node * copylist=new Node(head->data);
        copylist->next=NULL;
        Node* headc=head->next;
        Node* copyhead=copylist;
        while(headc!=NULL)
        {
         Node* temp=new Node(headc->data);
         copyhead->next=temp;
         temp->next=NULL;
         copyhead=temp;
         headc=headc->next;
        }
        Node* head2=reverse(copylist);
        while(head!=NULL && head2!=NULL)
        {
            if(head->data !=head2->data)
            {
            return false;
            }
            head=head->next;
            head2=head2->next;
        }
        return true;
        
    }
};
---------------------------------------APPROACH2
