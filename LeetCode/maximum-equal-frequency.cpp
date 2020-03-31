// Problem URL: https://leetcode.com/problems/maximum-equal-frequency/
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int mxF = 0, minF = 1, cntMxf = 0,ans = 1, i=0, distNum = 0;
        int cnt[100001], fcnt[100001];
        for (int i=0;i<=100000;i++) cnt[i]=fcnt[i]=0;

        for (auto x: nums) {
            // Minf process
            if (cnt[x] != 0) {
                fcnt[cnt[x]]--;
                if (fcnt[cnt[x]] == 0 and minF == cnt[x]) minF++;
                cnt[x]++;
                fcnt[cnt[x]]++;
            } else {
                minF = 1;
                cnt[x]++;
                fcnt[cnt[x]]++;
                distNum++;
            }
            // Maxf process
            if (cnt[x] == mxF)  cntMxf++;
            else if (cnt[x] > mxF) {
                mxF = cnt[x];
                cntMxf = 1;
            }
            // Algo
            if ((mxF == minF + 1 && cntMxf == 1) || (minF == 1 && fcnt[minF] == 1 && cntMxf == distNum - 1) || (mxF == 1 && minF == 1) || distNum == 1) ans = max(ans, i+1);
            i++;
        }

        return ans;
    }
};
