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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* pNode = ans;
        
        int k = 0;  
        while(l1 != NULL || l2 != NULL || k > 0 ){

            int a = l1 == NULL ? 0 : l1->val;
            int b = l2 == NULL ? 0 : l2->val;
            int v = a + b;
            v += k;
            
            pNode->val = v % 10;
            k = v / 10;
            
            if(l1 != NULL)l1 = l1->next;
            if(l2 != NULL)l2 = l2->next;
            if(l1 != NULL || l2 != NULL || k > 0){
                pNode->next = new ListNode(0);
                pNode = pNode->next;
            }
        }
        
        return ans;
    }
};