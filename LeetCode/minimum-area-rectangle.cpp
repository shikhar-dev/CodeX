// Problem URL: https://leetcode.com/problems/minimum-area-rectangle/
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set <pair<int,int>> st;
        int ans = INT_MAX;
        for (auto x: points) st.insert(make_pair(x[0],x[1]));
        for (int i = 0; i < points.size(); i++)
            for (int j = i + 1;j < points.size(); j++) {
                pair <int,int> p1,p2;
                p1 = make_pair(points[i][0], points[j][1]);
                p2 = make_pair(points[j][0], points[i][1]);
                if (points[i][0] != points[j][0] and points[j][1] != points[i][1] and st.count(p1) and st.count(p2))  ans = min(ans, abs(points[i][0]-points[j][0])*abs(points[i][1]-points[j][1]));
            }
        return (ans == INT_MAX) ? 0 : ans;
    }
};