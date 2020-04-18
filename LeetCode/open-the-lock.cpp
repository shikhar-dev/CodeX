// Problem URL: https://leetcode.com/problems/open-the-lock/
class Solution {
private:
    unordered_map <string,bool> vis;
    queue <pair <string,int>> q;
    int bfs(string target) {
        q.push(make_pair("0000",0));
        if (vis["0000"])    return -1;
        vis["0000"] = true;
        while (!q.empty()) {
            string node = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if (node == target) return lvl;

            for (int i = 0;i < 4;i++) {
                string newNode1 = node, newNode2 = node;
                newNode1[i] = (newNode1[i] == '0') ? '9' : newNode1[i]-1;
                newNode2[i] = (newNode2[i] == '9') ? '0' : newNode2[i]+1;
                if (!vis[newNode1]) {
                    q.push(make_pair(newNode1,lvl+1));
                    vis[newNode1] = true;
                }
                if (!vis[newNode2]) {
                    q.push(make_pair(newNode2,lvl+1));
                    vis[newNode2] = true;
                }
            }
        }
        return -1;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        for (auto x: deadends)  vis[x] = true;
        return bfs(target);
    }
};