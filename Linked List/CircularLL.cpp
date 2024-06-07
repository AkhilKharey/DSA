#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
    ~Node()
    {
        int val=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free from the value "<<val<<endl;
    }
};
void InsertNode(Node* &tail,int element,int d)
{
    // element vo h jiske aage hame dalna hai
    // handling the case  of empty list
    if(tail==NULL)
    {
    Node* newnode=new Node(d);
      tail=newnode;
      newnode->next=newnode;
    }
    else{
        // assuming that element is present is the list
        Node*curr=tail;
        while(curr->data!=element)
        {
            curr=curr->next;
        }
        // after executing the while loop element is found in the list aur vo curr wali position pe hoga 
         Node* newnode=new Node(d);
         newnode->next=curr->next;
         curr->next=newnode; 

    }
}
void deleteNode(Node* &tail,int value)
{
    if(tail==NULL)
    {
        cout<<"node is empty so nothing to delete please check again"<<endl;
    }
    else
    {
        // list is not empty
        // assume that value is present in the list
        Node* prev=tail;
        Node* curr=tail->next;
        while(curr->data!=value)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        // deleting single node  linked list
        if(curr==prev)
        {
            tail=NULL;
        }
        // >=2 node linked list
        else if(curr==tail)
        {
            // taki hamara tail wali node bachi rhe ni to traverse kaise karenge tail ko kahi bhi point kara sakte hai
            // kyuki circular linked list hai to fark ni paddta hai
            tail=prev;
        }

        curr->next=NULL;
        delete curr;

    }
}
void print(Node*&tail)
{
    Node* temp=tail;
    if(tail==NULL)
    {
        cout<<"empty list"<<endl;
        return;
    }
    // do while isliye laga rhe hai taki single node ko bhi print kara sake
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }
    while(tail!=temp);
    cout<<endl;
}
int main()
{
     Node* tail=NULL;
    //  element 3 k aage 1 daldo
     InsertNode(tail,3,1);
// print ke liye bas tail se kam chal jaega
     print(tail);
    //  element 1 k aage 2 daldo
     InsertNode(tail,1,2);
     print(tail);
     InsertNode(tail,2,3);
     print(tail);
     InsertNode(tail,3,4);
     print(tail);
     deleteNode(tail,2);
     print(tail);
     deleteNode(tail,3);
     print(tail);
     deleteNode(tail,4);
     print(tail);
     deleteNode(tail,1);
     print(tail);

}