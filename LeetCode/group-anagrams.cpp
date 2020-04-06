// Problem URL: https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector <pair <string,int>> vec;
        vector<vector<string>> ans;
        for (int i=0; i<strs.size();i++) {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            vec.push_back(make_pair(temp, i));
        }
        sort(vec.begin(),vec.end());
        for (int i=0,j=0;i<vec.size();) {
            vector <string> temp;
            while (j < vec.size() and vec[i].first==vec[j].first) {
                temp.push_back(strs[vec[j].second]);
                j++;
            }
            ans.push_back(temp);
            i=j;
        }
        return ans;
    }
};