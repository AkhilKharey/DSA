Node *removeDuplicates(Node *head)
{
    // Write your code herehttps://www.codingninjas.com/studio/problems/remove-duplicates-from-unsorted-linked-list_1069331?source=youtube&campaign=YouTube_Lovebabbar29thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar29thJan&leftPanelTab=1
    unordered_map<int, bool> same;
// unordered map ki time complexity kam hoti hai map se isliye ye use krenge
    if (head == NULL || head->next == NULL)
        return head;
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        if (same[curr->data] == true)
        {
            prev->next = curr->next;
            //  delete curr;
            curr = prev->next;
        }
        else
        {
            same[curr->data] = true;
            prev = curr;
            if (curr != NULL)
                curr = curr->next;
        }
    }
    return head;
}