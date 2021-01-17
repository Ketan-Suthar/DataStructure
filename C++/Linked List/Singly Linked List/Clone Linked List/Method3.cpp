/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution 
{
public:
    void alternatingSplitList(Node* a, Node **b) 
    {
        Node *head = a;
        if(!a || !a->next)
            return;
        *b = a->next;
        Node* temp;
        while(head)
        {
            temp = head->next;
            head->next = temp ? temp->next : temp;
            head = temp;
        }
    }
    void setRandomPointers(Node *head)
    {
        Node *trav = head, *next;
        while(trav)
        {
            next = trav->next->next;
            if(trav->random)
                trav->next->random = trav->random->next;
            trav = next;
        }
    }
    Node* copyRandomList(Node* head)
    {
        Node *new_head,*temp = nullptr, *trav = head;
        if(!head)
            return nullptr;
        while(trav)
        {
            Node *new_node = new Node(trav->val);
            // cout<<new_node->val<<' ';
            temp = trav->next;
            trav->next = new_node;
            new_node->next = temp;
            trav= temp;
        }
        setRandomPointers(head);
        alternatingSplitList(head, &new_head);
        
        return new_head;
    }
};