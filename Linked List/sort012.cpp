/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    // Write your code here.
    int zc=0;
    int oc=0;
    int tc=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==1)
        oc++;
        else if(temp->data==0)
        zc++;
        else if(temp->data==2)
        tc++;
        temp=temp->next;
    }
     temp=head;

    
        while(zc--&&temp!=NULL)
        {
            temp->data=0;
            temp=temp->next;
        }
        while(oc--&&temp!=NULL)
        {
            temp->data=1;
            temp=temp->next;
        }
    while(tc--&&temp!=NULL)
        {
            temp->data=2;
            temp=temp->next;
        }

    
    return head;
}
// ---------------------------------------------------------------------------------------APPROACH2
void InsertAtTail(Node* &tail,Node* temp)
{
  tail->next=temp;
  tail=temp;
}

Node* sortList(Node *head){
    // Write your code here.
    Node* zeroHead=new Node(-1);
    Node* zerotail=zeroHead;
    Node* oneHead=new Node(-1);
    Node* onetail=oneHead;
    Node* twoHead=new Node(-1);
    Node* twotail=twoHead;
    Node* temp=head;
    // create three seperate list for zero one two
    while(temp!=NULL)
    {
     if(temp->data==0)
     {
        InsertAtTail(zerotail,temp);
     }  
    else if(temp->data==1)
     {
          InsertAtTail(onetail,temp);
     }
    else 
     {
          InsertAtTail(twotail,temp);
     } 
     temp=temp->next;      
    }
    // merge three sublist
    // 1 wali list is not empty
    if(oneHead->next!=NULL)
    {
        zerotail->next=oneHead->next;
        onetail->next=twoHead->next;
    }
    // 1 wal list is empty
    else{
        zerotail->next=twoHead->next;
    }
    twotail->next=NULL;
    // UPDATE HEAD
    head=zeroHead->next;
    // DELETE DUMMY NODES
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;