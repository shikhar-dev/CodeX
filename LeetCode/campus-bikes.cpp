// Problem URL: https://leetcode.com/problems/campus-bikes/
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int cnt = 0;
        vector <int> ans(workers.size());
        vector <bool> visw(workers.size(),false), visb(bikes.size(), false);
        vector <pair<int,int>> arr[2002];
        for (int i=0; i<workers.size(); i++)
            for (int j =0;j < bikes.size(); j++)
                arr[abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1])].push_back(make_pair(i,j));

        for (int j =0 ;j<2002 and cnt < workers.size(); j++)
            if (!arr[j].empty())  {
                for (auto x: arr[j])
                    if (!(visw[x.first] || visb[x.second])) {
                        ans[x.first] = x.second;
                        visw[x.first] = true;
                        visb[x.second] = true;
                        cnt++;
                    }
            }
        return ans;
    }
};