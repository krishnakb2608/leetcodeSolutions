/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:lists){
            ListNode* temp=i;
            while(temp){pq.push(temp->val);temp=temp->next;}

        }
        ListNode*head=nullptr;
        ListNode*tail=nullptr;

        while(!pq.empty()){
            int temp=pq.top();
            pq.pop();
            ListNode* node=new ListNode(temp);
            if(!head){head=tail=node;continue;}
            tail->next=node;
            tail=node;
        
        }
        return head;
    }
};