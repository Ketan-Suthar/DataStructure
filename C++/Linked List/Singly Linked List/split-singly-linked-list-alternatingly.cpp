
/*
These are global variables to store heads of split lists
struct Node* a; //store head of first list
struct Node* b; //store head of second list

*/

void alternatingSplitList(struct Node* head) 
{
    a = head;
    if(!head || !head->next)
        return;
    b = head->next;
    struct Node* temp;
    while(head)
    {
        temp = head->next;
        head->next = temp ? temp->next : temp;
        head = temp;
    }
}