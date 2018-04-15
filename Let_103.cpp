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
public:
	void levOrder(TreeNode* root, vector<vector<int>>& v, int level)
	{
		if (root == NULL)return;

		if (level >= v.size()){
			vector<int> a;
			v.push_back(a);
		}
		v[level].push_back(root->val);

		levOrder(root->left, v, level + 1);
		levOrder(root->right, v, level + 1);
	}

	void dealVec(vector<vector<int>>& v)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (i % 2 == 1)
			{
				for (int j = 0; j < v[i].size()/2; j++)
				{
					swap(v[i][j], v[i][v[i].size() - 1 - j]);
				}
			}
		}
	}

	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> vec;
		levOrder(root, vec, 0);
		dealVec(vec);
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