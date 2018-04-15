class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        std:map<int, int> list;
        for(int i = 0; i < nums.size(); i++){
            list[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            int v = nums[i];
            int dest = target - v;
            if(list[dest] > 0 && list[dest] != i){
                answer.push_back(i);
                answer.push_back(list[dest]);
                break;
            }
        }
        return answer;
    }
};