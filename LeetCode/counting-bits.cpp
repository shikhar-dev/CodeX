// Problem URL: https://leetcode.com/problems/counting-bits/
class Solution {
public:
    vector<int> countBits(int num) {
        vector <int> ans;
        ans.push_back(0);
        if (num == 0)   return ans;
        ans.push_back(1);
        if (num == 1) return ans;
        while (ans.size() <= num) {
            int sz = ans.size();
            for (int i = 0;i < sz and ans.size() <= num; i++) ans.push_back(ans[i]+1);
        }
        return ans;
    }
};