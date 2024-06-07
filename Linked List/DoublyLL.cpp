#include <iostream>
using namespace std;
class Node
{
public:

    int data;
    Node *next;
    Node *prev;
    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int Value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free with the data  " << Value << endl;
    }
};
// traversing a linked list
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// getting a length of linked list
int getlength(Node *&head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length = length + 1;
        temp = temp->next;
    }
    return length;
}
// inserting at first position
void Insertathead(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {

        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
// inserting at last position
void Insertattail(Node *&tail, Node *&head, int data)
{
    Node *temp = new Node(data);
    // handling the case of empty list
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void InsertAtPosition(Node *&head, Node *&tail, int pos, int data)
{
    // if inserting at first position
    if (pos == 1)
    {
        Insertathead(head, tail, data);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // if inserting at last position
    if (temp->next == NULL)
    {
        Insertattail(tail, head, data);
        return;
    }
    // if inserting at any other position
    Node *NodeToInsert = new Node(data);
    NodeToInsert->next = temp->next;
    temp->next->prev = NodeToInsert;
    temp->next = NodeToInsert;
    NodeToInsert->prev = temp;
}
// deletion code
void deleteNode(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    // handling all other cases of deletion from middle or lasr
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            // curr  will denote the node to be deleted;
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {

            //  to update the tail if llast node is deleted
            tail = prev;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        if(curr->next!=NULL)
        curr->next->prev=prev;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    Insertathead(head, tail, 9);
    print(head);
    Insertathead(head, tail, 8);
    print(head);
    Insertattail(tail, head, 11);
    print(head);
    InsertAtPosition(head, tail, 3, 1);
    print(head);
    deleteNode(head, tail, 4);
    print(head);
  
}