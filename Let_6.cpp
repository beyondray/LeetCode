class Solution {
public:
    string convert(string s, int numRows) {
        int p = -1, len = s.size();
        char* buf = new char[len + 1];
        buf[len] = '\0';
        
        for(int i = 1; i <= numRows; i++)
        {
            int m = numRows + 1 - i;
            for(int j = i-1; j < len;)
            {
                buf[++p] = s[j];
                m = i != 1 && i != numRows ? numRows + 1 -m : 1;                
                int delta = 2 * (numRows - m);
				j += delta > 0 ? delta : 1;
            }
        }
        string ans(buf);
        delete[] buf;
        return ans;
    }
};