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
    ListNode* reverse(ListNode* head){
        ListNode* cur=NULL;
        while(head){
            ListNode* next=head->next;
            head->next=cur;
            cur=head;
            head=next;
        }
        return cur;
    }

  
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast= head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* cur=NULL;
        slow->next=reverse(slow->next);
        ListNode* mid=slow->next;
        while(mid!=NULL){
            if(head->val!=mid->val){
                return false;
            }
            head=head->next;
            mid=mid->next;
        }
        
        return true;

    }
};