// Problem URL: https://leetcode.com/problems/subsets/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(),tot = (1<<n);
        vector<vector<int>> ans;
        for (int i = 0; i < tot; i++) {
            int bin = i;
            vector <int> temp;
            int j = 0;
            while (bin) {
                if (bin&1) temp.push_back(nums[j]);
                bin = (bin >> 1);
                j++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};