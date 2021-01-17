class Solution 
{
public:
    Node* copyRandomList(Node* head)
    {
        Node *new_head,*temp = nullptr, *trav = head;
        map<Node*, Node*> m;
        if(!head)
            return nullptr;
        while(trav)
        {
            Node *new_node = new Node(trav->val);
            // cout<<new_node->val<<' ';
            Node *random = trav->random;
            m[trav] = new_node;
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
        temp = new_head;
        trav = head;
        while(temp && trav)
        {
            temp->random = m[trav->random];
            temp = temp->next;
            trav = trav->next;
        }
        return new_head;
    }
};