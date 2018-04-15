class Solution {
public:
    static const int maxn = 1010;
    int dp[maxn][maxn];
    
    string longestPalindrome(string s) {

        if(s.size() == 0){
            return "";
        }
        
        string ans;
        int cnt = 1;
        ans = s[0];
        
        for(int i = 0; i < s.size()-1; i++){
            dp[i][i] = 1;
            
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = 1;
                if(cnt == 1)
                {
                    cnt = 2;
                    ans = s.substr(i, 2);
                }
            }
        }
        dp[s.size()-1][s.size()-1] = 1;
        
        //state transfer
        for(int L = 3; L <= s.size(); L++)
        {
            for(int i = 0; i + L -1 < s.size(); i++)
            {
                int j = i + L -1;
                if(s[i] == s[j] && dp[i+1][j-1] == 1)
                {
                    dp[i][j] = 1;
                    if(cnt != L)
                    {
                        cnt = L;
                        ans = s.substr(i, L);
                    }
                }
            }
        }
        
        return ans;
    }
};