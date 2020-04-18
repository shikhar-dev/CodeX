// Problem URL: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
class Solution {
private:
    map <int,int> mp;
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        for (auto x: nums)  mp[x]++;
        if (nums.size() % k != 0)   return false;
        int m = nums.size()/k, cnt = 0;

        while (cnt < m) {
            vector <int> temp;
            for (auto x: mp) {
                if (temp.size() == k ) break;
                if (!temp.empty() and temp.back() != x.first - 1) return false;
                temp.push_back(x.first);
            }
            if (temp.size() < k) return false;
            for (auto x: temp) {
                mp[x]--;
                if (!mp[x]) mp.erase(x);
            }
            cnt++;
        }
        return true;
    }
};