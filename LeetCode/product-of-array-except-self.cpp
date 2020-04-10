// Problem URL: https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> ans(nums);
        int mul = 1;
        for (int i = 0; i < nums.size()- 1; i++)
            nums[i+1] *= nums[i];
        for (int i = nums.size() - 1; i > -1; i--) {
            if (i == 0) nums[0] = mul;
            else nums[i] = nums[i-1]*mul;
            mul *= ans[i];
        }
        return nums;
    }
};