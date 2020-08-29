
Node *reverse(Node *head)
{
    Node *prev = NULL;
    while(head != NULL)
    {
        Node *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    //Your code here
    Node *fast = head, *slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = reverse(slow);
    fast = head;
    while(slow != NULL)
    {
        if(slow->data != fast->data)
            return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}