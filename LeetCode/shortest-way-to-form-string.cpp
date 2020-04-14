// Problem URL: https://leetcode.com/problems/shortest-way-to-form-string/
// Time: O(nlogn) Space: O(n)
class Solution {
private:
    vector <int> alpha[26];
public:
    int shortestWay(string source, string target) {
        for (int i = 0; i < source.size(); i++)     alpha[source[i]-'a'].push_back(i);
        int cnt = 1, lastIndex = -1;
        for (auto x: target) {
            int charIndex = x-'a';
            if (alpha[charIndex].empty())   return -1;
            vector <int> :: iterator it;
            it = upper_bound(alpha[charIndex].begin(), alpha[charIndex].end(), lastIndex);
            if (it == alpha[charIndex].end()) {
                cnt++;
                lastIndex = alpha[charIndex][0];
            }
            else {
                lastIndex = *it;
            }
        }
        return cnt;
    }
};