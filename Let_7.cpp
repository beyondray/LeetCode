#include<climits>

class Solution {
public:
    int reverse(int x) {
		long long ans = 0;
		while (x != 0)
		{
			ans *= 10;
			ans += (x % 10);
			x /= 10;
		}
        
		int _ans = ans >= 0 ? (ans > INT_MAX ? 0 : (int)ans) \
			: (ans < INT_MIN ? 0 : (int)ans);
        
        return _ans;
    }
};