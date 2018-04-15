class Solution {
public:
    int myAtoi(string str) {

        int i = 0;
        while(i < str.size() && str[i] == ' ')i++;
        if(i >= str.size())return 0;
        else if(!(str[i] >= '0' && str[i] <= '9') && str[i] != '+' && str[i] != '-')
        {
            return 0;
        }
        
        //处理符号或第一个字符
        long long _ans = 0;
        long long sign = 1;
        if(str[i] == '-'){
            sign = -1;
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {
            _ans = (str[i] - '0');
        }
        ++i;
        
        //处理之后的字符
        for(; i < str.size(); i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                _ans *= 10;
                _ans += (str[i] - '0');
                if(_ans*sign > INT_MAX || _ans*sign < INT_MIN){
                    break;
                }
            }
            else{
                break;
            }
        }
        _ans *= sign;
        
        //处理超出范围的数
        int ans = _ans > INT_MAX ? INT_MAX : _ans < INT_MIN ? INT_MIN : _ans;
        return ans;
    }
};