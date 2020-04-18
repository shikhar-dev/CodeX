// Problem URL: https://leetcode.com/problems/find-and-replace-in-string/
class Solution {
private:
    bool match(string base, string pat, int index) {
        int j;
        for (j = 0;j < pat.size() and index+j < base.size(); j++)
            if (base[index+j] != pat[j])
                return false;
        return j == pat.size()
    }
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string ans;
        vector <pair<string,string>> vec(S.size());
        for (int i=0; i<sources.size();i++)
            vec[indexes[i]] = make_pair(sources[i], targets[i]);

        for (int i = 0; i< S.size(); i++) {
            if (!vec[i].first.empty() and match(S,vec[i].first,i)) {
                ans += vec[i].second;
                i += vec[i].first.size() - 1;
            } else
                ans += S[i];
        }
        return ans;
    }
};