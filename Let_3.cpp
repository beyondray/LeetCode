class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::map<char, bool> strMap;
        int l = 0, r = 0, maxL = 0;
        
        for(r = 0; r < s.size(); r++)
        {
            if(!strMap[s[r]]){
                strMap[s[r]] = true;
            }
            else{
                int len = r - l;
                if(len > maxL){
                    maxL = len;
                }
                
                while(s[l] != s[r]){
                    strMap[s[l++]] = false;
                }
                ++l;
            }
        }
        
        int len = r - l;
        if(len > maxL){
            maxL = len;
        }
        
        return maxL;
    }
};