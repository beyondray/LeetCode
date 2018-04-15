#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void genAllParenthesis(vector<string>& res, string str, int n, int lPar, int rPar, int cnt)
	{
		if (str.size() == 2 * n){
			res.push_back(str);
			return;
		}

		if (cnt > 0){
			if (rPar < n){
				string s2 = str;
				s2.push_back(')');
				genAllParenthesis(res, s2, n, lPar, rPar+1, cnt-1);
			}
		}

		if (lPar < n){
			string s1 = str;
			s1.push_back('(');
			genAllParenthesis(res, s1, n, lPar+1, rPar, cnt+1);
		}
	}

	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		genAllParenthesis(ans, string(), n, 0, 0, 0);
		return ans;
	}
};

ostream& operator<<(ostream& os, vector<string>& rhs)
{
	for (auto & ele : rhs)
	{
		os << ele.c_str() << endl;
	}
	return os;
}

int main()
{
	Solution s;
	cout << s.generateParenthesis(3);
}