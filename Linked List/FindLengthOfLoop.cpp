//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        cout<< countNodesinLoop(head) << endl;
    }
	return 0;
}

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

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    // Code here
    if(head==NULL||head->next==NULL)return 0;
    Node* slow=head;
    Node*fast=head;
    slow=slow->next;
    fast=fast->next->next;
    while(fast!=NULL && fast!=slow)
    {
        fast=fast->next;
        if(fast!=NULL) fast=fast->next;
        slow=slow->next;
    }
    if(fast==NULL) return 0;
    // now fast==slow means cycle is present 
    // starting point pata krne k liye point of intersection  se same speed pe 
    // chalenge fir jahe pe milenge vo starting point
    slow=head;
    while(fast!=slow)
    {
        slow=slow->next;
        fast=fast->next;
    }
    Node* startNode=slow;
    slow=slow->next;
    if(slow==startNode) return 1;
    int count =1;
    while(slow!=startNode)
    {
        slow=slow->next;
        count++;
    }
    return count;
}