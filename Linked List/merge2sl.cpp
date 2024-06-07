Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    // https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1
    if(head1==NULL)
    return head2;
    if(head2==NULL)
    return head1;
    if(head1->next==NULL)
    {
        Node* temp=head1;
        head1=head2;
        head2=temp;
    }
    if(head1->data > head2->data)
    {
        Node* temp=head2;
        head2=head2->next;
        temp->next=head1;
        head1=temp;
    }
    
    Node* prev=head1;
    Node* curr=head1->next;
    while(curr!=NULL&&head2!=NULL)
    {
        if(head2->data >= prev->data && head2->data <= curr->data)
        {
            Node* temp=head2;
            head2=head2->next;
            prev->next=temp;
            temp->next=curr;
            prev=temp;
            
        }
        else if(curr->next==NULL)
        {
            curr->next=head2;
            curr=NULL;
        }
        else 
        {
        prev=curr;
        curr=curr->next;
        }
    }
    return head1;
}  