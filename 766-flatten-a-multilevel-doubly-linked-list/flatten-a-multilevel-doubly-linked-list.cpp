/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp=head;
        while(temp){
            Node * remember=temp->next;
            if(temp->child){
                Node* kid=temp->child;
                while(kid->next){
                    kid=kid->next;
                }
                temp->next=temp->child;
                temp->child->prev=temp;
                kid->next=remember;
                if(remember)remember->prev=kid;
                temp->child=nullptr;

            }
            temp=temp->next;
        }
        return head;
    }

};