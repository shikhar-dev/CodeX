// Problem URL: https://leetcode.com/problems/daily-temperatures/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector <int> dp;
        for (int i = 0; i < T.size(); i++) dp.push_back(i);
        for (int i = T.size()-2; i > -1; i--) {
            int j = i+1;
            while (j!=dp[j] and T[j] <= T[i]) j = dp[j];
            if (T[j] > T[i]) dp[i] = j;
        }
        for (int i = 0; i < dp.size(); i++) dp[i] -= i;
        return dp;
    }
};