// Problem URL: https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        vector <int> freq[nums.size() + 1],ans;
        for (auto x: nums) mp[x]++;
        for (auto x: mp) freq[x.second].push_back(x.first);
        for (int i = nums.size();ans.size() < k and i > 0;i--) {
            for (auto x: freq[i])
                if (ans.size() < k)
                    ans.push_back(x);
        }
        return ans;
    }
};