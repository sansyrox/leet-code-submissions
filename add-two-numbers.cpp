// Question
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example:

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* insertAtHead(ListNode* head, int d){
        
        if(head==NULL){
            return new ListNode(d);
        }
        
        ListNode* temp = new ListNode(d);
        temp->next = head;
        head = temp;
        
        return head;
        
        
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        string s = "";
        int carry = 0;
        
        while(l1 != NULL and l2!=NULL){
            s += to_string((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        
        
        while(l1 != NULL){
            s += to_string((l1->val + carry)%10);
            // carry = 0;
            carry = (l1->val + carry ) /10;
            l1 = l1->next;
        }
        
        while(l2 != NULL){
            s+= to_string((l2->val + carry)%10);
            // carry = 0;
            carry = (l2->val + carry ) /10;
            l2 = l2->next;
        }
        
        if(l1==NULL and l2==NULL and carry!=0){
            s += to_string(carry);
            carry = 0;
        }
        
        // cout<<s<<" "<< carry<<endl;
        reverse(s.begin(),s.end());
        
        ListNode* returnHead = NULL;
        
        for(auto i:s){
            returnHead = insertAtHead(returnHead, i-'0');
        }
        
        
        return returnHead;
        
    }
};