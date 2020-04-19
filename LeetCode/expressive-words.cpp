// Problem URL: https://leetcode.com/problems/expressive-words/
class Solution {
    pair <string,vector <int>> compress(string str) {
        vector <int> ans;
        string sans="";
        for (int i =0,j=0; i < str.size(); ) {
            int cnt = 0;
            sans += str[i];
            while (j < str.size() and str[j] == str[i]) cnt++,j++;
            i = j;
            ans.push_back(cnt);
        }
        return make_pair(sans,ans);
    }

    bool check(pair <string,vector<int>> s, pair <string,vector<int>> pat) {
        if (s.first != pat.first) return false;
        for (int i = 0;i < s.second.size(); i++)
            if (pat.second[i] != s.second[i] and (pat.second[i] > s.second[i] || s.second[i] < 3))  return false;
        return true;
    }
public:
    int expressiveWords(string S, vector<string>& words) {
        pair <string,vector<int>> sp = compress(S);
        int ans = 0;
        for (auto x: words) {
            pair <string,vector<int>> temp = compress(x);
            if (check(sp,temp)) ans++;
        }
        return ans;
    }
};