// Problem URL: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector <int> groups[502];
        vector <vector<int>> ans;

        int i = 0;
        for (auto x: groupSizes) {
            groups[x].push_back(i);
            i++;
            if (groups[x].size()==x) {
                ans.push_back(groups[x]);
                groups[x].clear();
            }
        }

        return ans;
    }
};