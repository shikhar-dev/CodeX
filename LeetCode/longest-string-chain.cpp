// Problem URL: https://leetcode.com/problems/longest-string-chain/
class Solution {
private:
    bool checkPre(string a, string b) {
        if (b.size() != a.size() + 1)   return false;
        bool flag = false;
        for (int i=0,j=0; i < a.size();) {
            if (a[i] != b[j] and !flag) {
                flag = true;
                j++;
            }
            else if (a[i] != b[j] and flag) return false;
            else i++,j++;
        }
        return true;
    }
    vector <string> vec[18];
    vector <int> dp[18];
public:
    int longestStrChain(vector<string>& words) {
        int ans = 1;
        for (auto x: words) {
            vec[x.size()].push_back(x);
            dp[x.size()].push_back(1);
        }
        for (int i = 15;i > 0; i--)
            for (int j = 0; j < vec[i].size(); j++) {
                for (int k = 0; k < vec[i+1].size(); k++)
                    if (checkPre(vec[i][j],vec[i+1][k]))
                        dp[i][j] = max(dp[i][j], dp[i+1][k] + 1);
                ans = max(ans,dp[i][j]);
            }

        return ans;
    }
};