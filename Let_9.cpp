class Solution {
public:
    bool isPalindrome(int x) {
        int y = 0, z = x;
        while(x != 0){
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        return y == z && y >= 0;
    }
};