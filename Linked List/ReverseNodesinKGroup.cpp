// https://leetcode.com/problems/reverse-nodes-in-k-group/
class Solution
{
public:
    int getLength(ListNode *head)
    {
        int len = 0;
        while (head != NULL)
        {
            head = head->next;
            len++;
        }
        return len;
    }
    ListNode *reversek(ListNode *head, int k, int len)
    {
        if (head == NULL || head->next == NULL || k == 1 || len < k)
        {
            return head;
        }
        // reverse first k nodes if len is greater than k
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        // recursion laga k aage ki nodes ka dekh lenge
        if (next != NULL)
        {
            head->next = reversek(next, k, len - k);
        }
        head = prev;
        return head;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int len = getLength(head);
        return reversek(head, k, len);
    }
};