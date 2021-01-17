int getNthFromLast(Node *head, int n)
{
    if(!head) return -1;
    Node *ahead=head, *behind=head;
    
    for(int i=1;i<n && ahead;i++)
    {
        ahead = ahead->next;
    }
    if(!ahead)
        return -1;
    for(; ahead->next; ahead=ahead->next, behind=behind->next);
    return behind->data;
}