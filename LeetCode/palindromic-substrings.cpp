// Problem URL: https://leetcode.com/problems/palindromic-substrings/
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0,i,j;
        for (i = 0;i<s.size();i++)
            for (j=0; i+j < s.size() and i-j > -1; j++)
                if (s[i+j] == s[i-j]) ans++;
                else break;
        for (i=0; i < s.size() - 1; i++)
            for (j=0; i-j > -1 and i+1+j < s.size(); j++)
                if (s[i+1+j] == s[i-j]) ans++;
                else break;
        return ans;
    }
};