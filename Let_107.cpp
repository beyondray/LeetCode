/**
* Definition for a binary tree node.
*/
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int maxLev;

public:
	Solution() :maxLev(-1){};

	void searchLev(TreeNode* root, int level)
	{
		if (root == NULL)return;
		if (level > maxLev)maxLev = level;
		searchLev(root->left, level + 1);
		searchLev(root->right, level + 1);
	}

	void levOrder(TreeNode* root, vector<vector<int>>& v, int level)
	{
		if (root == NULL)return;

		int _inLev = maxLev - level;
		v[_inLev].push_back(root->val);

		levOrder(root->left, v, level + 1);
		levOrder(root->right, v, level + 1);
	}

	vector<vector<int>> levelOrder(TreeNode* root) {
		searchLev(root, 0);
		vector < vector<int>> vec(maxLev + 1);
		levOrder(root, vec, 0);
		return vec;
	}
};

int main()
{
	struct TreeNode a(5);
	Solution s;
	
	vector<vector<int>> v = s.levelOrder(&a);
	for (int i = 0; i < v.size(); i++)
	{
		for (auto& ele : v[i])
		{
			cout << ele << " ";
		}
		cout << endl;
	}
	return 0;
}