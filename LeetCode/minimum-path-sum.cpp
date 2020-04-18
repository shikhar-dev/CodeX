// Problem URL: https://leetcode.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(),i,j;
        for (i=0; i < n; i++)
            for (j = 0;j < m;j++)
                if (!(i == 0 and j == 0)) {
                    int m1 = INT_MAX, m2 = INT_MAX;
                    if (i > 0) m1 = grid[i-1][j];
                    if (j > 0) m2 = grid[i][j-1];
                    grid[i][j] += min(m1,m2);
                }
        return grid[n-1][m-1];
    }
};