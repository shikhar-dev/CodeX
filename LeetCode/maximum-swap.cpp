// Problem URL: https://leetcode.com/problems/maximum-swap/
class Solution {
public:
    int maximumSwap(int num) {
        vector <int> n, sortN;
        while (num) {
            n.push_back(num%10);
            num /= 10;
        }
        reverse(n.begin(),n.end());
        for (int i=0;i<n.size();i++) sortN.push_back(n[i]);
        sort(sortN.begin(),sortN.end(),greater<int>());
        for (int i=0;i<sortN.size();i++)
            if (sortN[i] != n[i]) {
                for (int j = n.size()-1; j>i;j--)
                    if (n[j] == sortN[i]) {
                        swap(n[i],n[j]);
                        break;
                    }
                break;
            }
        int ans = 0;
        for (auto x: n) ans = ans*10 + x;
        return ans;
    }
};