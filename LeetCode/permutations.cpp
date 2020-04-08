// Problem URL: https://leetcode.com/problems/permutations/
class Solution {
private:
    vector<vector<int>> permuteRecur(vector <int> arr) {
        vector<vector<int>> temp,ans;

        for (auto x: arr) {
            vector <int> vec;
            for (auto y: arr)
                if (x != y) vec.push_back(y);
            temp = permuteRecur(vec);
            for (auto brr: temp) {
                brr.insert(brr.begin(),x);
                ans.push_back(brr);
            }
            if (temp.empty()) {
                vec.push_back(x);
                ans.push_back(vec);
            }
        }

        return ans;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return permuteRecur(nums);
    }
};