class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, compareH = 0;
        for(int i = 0; i < height.size()-1; i++)
        {
            if(height[i] <= compareH)continue;
            
            int maxH = 0;
            for(int j = height.size()-1; j > i; j--)
            {
                if(height[j] >= height[i]){
                    int area = height[i] * (j-i);
                    if(area > ans){
                        ans = area;
                        compareH = height[i];
                        break;
                    }
                }
                else{
                    if(height[j] > maxH){
                        maxH = height[j];
                        int area = maxH * (j-i);
                        if(area > ans){
                            ans = area;
                            compareH = height[i];
                        }
                    }
                }
            }
            
        }
        return ans;
    }
};