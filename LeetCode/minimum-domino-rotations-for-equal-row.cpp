// Problem URL: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
class Solution {
private:
    int makeSame(vector<int>& A, vector<int>& B, int same) {
        int ans = 0;
        for (int i = 0; i < A.size(); i++)
            if (A[i] != same and B[i] != same) return INT_MAX;
            else if (A[i] == same) continue;
            else if (B[i] == same) ans++;
        return ans;
    }
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int val1,val2,val3,val4;
        val1 = makeSame(A,B,A[0]);
        val2 = makeSame(B,A,A[0]);
        val3 = makeSame(A,B,B[0]);
        val4 = makeSame(B,A,B[0]);

        int ans = min({val1,val2,val3,val4});

        return (ans == INT_MAX) ? -1 : ans;
    }
};