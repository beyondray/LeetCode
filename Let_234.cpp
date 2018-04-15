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
    bool isPalindrome(ListNode* head) {
		if (head == NULL)return true;

		std::vector<int> v;
		ListNode*p = head;
		while (p != NULL)
		{
			v.push_back(p->val);
			p = p->next;
		}

		bool bRe = true;
		for (int i = 0, j = v.size() - 1; i < j; i++, j--)
		{
			if (v[i] != v[j]){
				bRe = false;
				break;
			}
		}
		return bRe;
    }
};