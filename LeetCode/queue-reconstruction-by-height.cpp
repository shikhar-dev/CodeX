// Problem URL: https://leetcode.com/problems/queue-reconstruction-by-height/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector <vector<int>> ans, ref;
        ref = people;

        while (ans.size() < people.size()) {
            int mn = INT_MAX, index;
            for (int i = 0; i< people.size(); i++)
                if (people[i][1] == 0 and people[i][0] < mn) {
                    mn = people[i][0];
                    index = i;
                }
            ans.push_back(ref[index]);
            for (int i = 0; i<people.size(); i++)
                if (people[i][0] <= mn) people[i][1]--;
        }
        return ans;
    }
};