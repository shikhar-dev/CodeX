// Problem URL: https://leetcode.com/problems/valid-parenthesis-string/solution/
class Solution {
public:
    bool checkValidString(string s) {
        int starCnt = 0, cnt = 0;
        for (int i = 0;i < s.size(); i++) {
            if (s[i] == '*') {
                starCnt ++;
                continue;
            }
            else if (s[i] == '(') cnt++;
            else cnt--;
            if (cnt < 0) {
                if (starCnt == 0)
                    return false;
                else starCnt --;
                cnt = 0;
            }
        }

        for (int i = s.size() - 1, starCnt = 0, cnt = 0;i > -1; i--) {
            if (s[i] == '*') {
                starCnt ++;
                continue;
            }
            else if (s[i] == '(') cnt--;
            else cnt++;
            if (cnt < 0) {
                if (starCnt == 0) return false;
                else starCnt --;
                cnt = 0;
            }
        }

        return true;
    }
};