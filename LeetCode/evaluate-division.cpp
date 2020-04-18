// Problem URL: https://leetcode.com/problems/evaluate-division/
class Solution {
private:
    const static int N = 100;
    unordered_map <string,int> mp;
    vector <pair<int,double>> graph[N];
    bool vis[N];
    double ans = -1.0;
    void dfs(int source,int destination, double product) {
        if (source == destination) {
            ans = product;
            return;
        }
        vis[source] = true;
        for (auto x: graph[source])
            if (!vis[x.first])
                dfs(x.first, destination, product * x.second);
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> vec;
        int cnt = 1;
        for (int i = 0; i < equations.size(); i++) {
            if (!mp[equations[i][0]])  mp[equations[i][0]]=cnt++;
            if (!mp[equations[i][1]])  mp[equations[i][1]]=cnt++;
            int a = mp[equations[i][0]],b = mp[equations[i][1]];
            graph[a].push_back(make_pair(b,values[i]));
            graph[b].push_back(make_pair(a,1.00/values[i]));
        }
        for (auto x: queries) {
            int a = mp[x[0]], b = mp[x[1]];
            if (a == 0 || b == 0) {
                vec.push_back(-1.00);
                continue;
            }
            for (int i = 0; i< N; i++) vis[i] = false;
            ans = -1.00;
            dfs(a,b,1.00);
            vec.push_back(ans);
        }
        return vec;
    }
};