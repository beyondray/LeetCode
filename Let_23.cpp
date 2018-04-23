/**
* Definition for singly-linked list.
*/
#include<iostream>
#include<vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* getMinNode(vector<ListNode*>& lists){
		if (lists.size() == 0)return NULL;

		ListNode* cur = lists[0];
		int idx = 0;

		for (int i = 1; i < lists.size(); i++)
		{
			if (lists[i] != NULL)
			{
				if (cur == NULL || lists[i]->val < cur->val)
				{
					cur = lists[i];
					idx = i;
				}
			}
		}
		
		if (cur != NULL){
			lists[idx] = lists[idx]->next;
		}
		return cur;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* next = NULL, *cur = NULL, *root = NULL;
		while ((next = getMinNode(lists)) != NULL)
		{
			if (cur == NULL){
				cur = new ListNode(next->val);
				root = cur;
			}
			else
			{
				cur->next = new ListNode(next->val);
				cur = cur->next;
			}
		}
		return root;
	}
};

int main()
{
	return 0;
}