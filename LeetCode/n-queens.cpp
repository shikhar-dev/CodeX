// Problem URL: https://leetcode.com/problems/n-queens/
class Solution {
private:
    vector<vector<string>> ans;
    vector<string> mat;
    int N;

    void fillRow(int row, int left) {
        if (left == 0)  {
            ans.push_back(mat);
            return;
        }
        for (int i = 0; i < N; i++)
            if (can_place(row,i)) {
                mat[row][i] = 'Q';
                fillRow(row + 1, left-1);
                mat[row][i] = '.';
            }
    }

    bool can_go(int r,int c) {
        if (r < N and r > -1 and c < N and c > -1) return true;
        return false;
    }

    bool can_place(int row,int col) {
        int dx[3] = {-1, 0, 1}, dy[3] = {-1, 0, 1};
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                if (!(dx[i]==0 and dy[j]==0)){
                    int r=row, c=col;
                    while (can_go(r,c)) {
                        if (mat[r][c] == 'Q')   return false;
                        r += dx[i];
                        c += dy[j];
                    }
                }
            }
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string str(n,'.');
        N = n;
        for (int i = 0;i < n; i++)  mat.push_back(str);
        fillRow(0,n);
        return ans;
    }

};