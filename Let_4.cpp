class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s = nums1.size() + nums2.size();
        int a = s / 2;
        int b = s % 2 == 0 ? s/2-1 : a;
        
        vector<int> nums;
        int i = 0, j = 0;
        while(i < nums1.size() || j < nums2.size())
        {
            if(i < nums1.size() && j < nums2.size())
            {
                if(nums1[i] < nums2[j]){
                    nums.push_back(nums1[i++]);
                }
                else{
                    nums.push_back(nums2[j++]);
                }
            }
            else if(i >= nums1.size())
            {
                nums.push_back(nums2[j++]);
            }
            else{
                nums.push_back(nums1[i++]);
            }
            
            if(nums.size()-1 >= a)break;
        }

        double ans = (double)(nums[a] + nums[b])/2.0;
        return ans;
    }
};