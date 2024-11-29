#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // destructor
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
void InsertAtHead(Node *&head, int d)
{
    // create a new node
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void InsertAtMiddle(Node *&head, Node *&tail, int pos, int data)
{
    Node *temp = head;
    int cnt = 1;
    if (pos == 1)
    // case to handle inserting at 1st position and update the head
    {
        InsertAtHead(head, data);
        return;
    }

    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // case to handle insetting at last position and update the tail
    if (temp->next == NULL)
    {
        InsertAtTail(tail, data);
        return;
    }
    Node *NodeToInsert = new Node(data);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;
}
void deleteNode(int position, Node *&head, Node *&tail)
{
    if (position == 1)
    {
        // to delete the 1st node as there is no previous node
        Node *temp = head;
        head = head->next;
        // free memory of the start node
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {
            // to update tail if last node is deleted
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

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

int main()
{
    // create a new node
    Node *node1 = new Node(10);
    // cout<<node1 ->data<<endl;
    // cout<<node1 ->next<<endl;
    // /head pointed to node 1
    Node *head = node1;
    Node *tail = node1;
    print(head);
    InsertAtHead(head, 12);
    print(head);
    InsertAtHead(head, 15);
    print(head);
    InsertAtTail(tail, 14);
    print(head);
    InsertAtMiddle(head, tail, 3, 13);
    print(head);
    deleteNode(5, head, tail);
    print(head);
    cout << "head is" << head->data << endl;
    cout << "tail is" << tail->data << endl;
    return 0;
}