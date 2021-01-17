// this will not work if twp node contains same data

Node *findNode(Node *head, int x)
{
    Node *temp = head;
    while(temp && temp->data != x)
        temp = temp->next;
    return temp;
}

Node *copyList(Node *head) 
{
    Node *new_head,*temp = nullptr, *trav = head;
    
    if(!head)
        return nullptr;
    while(trav)
    {
        Node *new_node = new Node(trav->data);
        // cout<<new_node->data<<' ';
        if(temp)
        {
            temp->next = new_node;
            temp = temp->next;
        }
        else
        {
            new_head = new_node;
            temp = new_head;
        }
        trav= trav->next;
    }
    // cout<<endl;
    trav = head;
    temp = new_head;
    while(trav)
    {
        Node *find = nullptr;
        if(trav->arb)
            find = findNode(new_head, trav->arb->data);
        temp->arb = find;
        temp = temp->next;
        trav= trav->next;
    }
    return new_head;
}