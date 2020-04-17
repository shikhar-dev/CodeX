// Problem URL: https://leetcode.com/problems/hand-of-straights/
class Solution {
    map <int,int> mp;
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        for (auto x: hand) mp[x]++;
        while (!mp.empty()) {
            int  i = 0, last = -1;
            vector <int> dl;
            for (auto x: mp) {
                if (i == W) break;
                if (last != -1 and last + 1 != x.first) return false;
                last = x.first;
                mp[x.first]--;
                if (mp[x.first] == 0) dl.push_back(x.first);
                i++;
            }
            if (i != W) return false;
            for (auto x: dl) mp.erase(x);
        }
        return true;
    }
};