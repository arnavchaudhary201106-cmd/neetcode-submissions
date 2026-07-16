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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        return;
       ListNode* l1 = head;
       ListNode* l2 = head;
       while(l2->next!=NULL && l2->next->next!=NULL){
        l1=l1->next;
        l2=l2->next->next;
       }
       ListNode* middle = l1->next;
       l1->next=NULL;
       ListNode*next =NULL;
       ListNode* prev =NULL;
       while(middle!=NULL){
        next= middle->next;
        middle->next = prev;
        prev=middle;
        middle =next;
       }
       ListNode *first=head;
       ListNode *secondHalf = prev;
    
    while(secondHalf!=NULL){
        ListNode *temp1=first->next;
        ListNode *temp2 = secondHalf->next;
        first->next = secondHalf;
        secondHalf->next=temp1;
        first = temp1;
        secondHalf=temp2;
    }
    }
};
