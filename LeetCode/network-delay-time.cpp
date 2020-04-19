// Problem URL: https://leetcode.com/problems/network-delay-time/
class Solution {
private:
    int n,source;
    vector <pair<int,int>> graph[101];
    bool vis[101] = {false};
    int dist[101] = {INT_MAX};
    priority_queue <pair <int,int>, vector <pair<int,int>>, greater<pair<int,int>>> pq;

    int djikstra() {
        pq.push(make_pair(0,source));
        while (!pq.empty()) {
            while (!pq.empty() and vis[pq.top().second]) pq.pop();
            if (pq.empty()) break;
            int node = pq.top().second, d = pq.top().first;
            pq.pop();
            dist[node] = d;
            vis[node] = true;

            for (auto x: graph[node])
                if (!vis[x.first] and d + x.second < dist[x.first]) {
                    dist[x.first] = d + x.second;
                    pq.push(make_pair(dist[x.first], x.first));
                }
        }

        int mx = 0 ;
        for (int i = 0; i < n; i++) mx = max(mx, dist[i]);
        return (mx == INT_MAX) ? -1 : mx;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        n = N, source = K-1;
        for (int i = 0; i<n;i++) vis[i] = false, dist[i] = INT_MAX;
        for (auto x: times)
            graph[x[0]-1].push_back(make_pair(x[1]-1,x[2]));
        return djikstra();
    }
};