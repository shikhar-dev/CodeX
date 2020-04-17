// Problem URL: https://leetcode.com/problems/number-of-islands/
class Solution {
private:
    int n,m;
    vector<vector<char>>graph;
    vector <vector <bool>> vis;

    bool can_go(int r, int c) {
        if (r > -1 and r < n and c > -1 and c < m and graph[r][c] == '1' and vis[r][c] == false) return true;
        else return false;
    }

    void dfs(int r, int c) {
        if (!can_go(r,c)) return;
        vis[r][c] = true;
        dfs(r-1,c);
        dfs(r+1,c);
        dfs(r,c-1);
        dfs(r,c+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        if (grid.size() == 0) return 0;

        for (auto x: grid) {
            vector <bool> temp(x.size(), false);
            vis.push_back(temp);
        }

        graph = grid;
        n = graph.size();
        m = graph[0].size();

        int ans = 0;
        for (int i = 0;i < grid.size(); i++)
            for (int j = 0;j < grid[i].size(); j++)
                if (can_go(i,j)) {
                    ans++;
                    dfs(i,j);
                }

        return ans;

    }
};