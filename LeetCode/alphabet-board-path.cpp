// Problem URL: https://leetcode.com/problems/alphabet-board-path/submissions/

class Solution {
public:
    string alphabetBoardPath(string target) {
        string realTarget = "a" + target;
        string ans= "";
        for (int i = 0;i < realTarget.size() - 1; i++)
            ans += aToB(realTarget[i], realTarget[i+1]) + "!";
        return ans;
    }

private:
    string aToB(char a, char b) {
        pair <int,int> corA = mapCharToCor(a);
        pair <int,int> corB = mapCharToCor(b);

        char toPrint = 'U';
        string xT = "";
        if (corA.first < corB.first) toPrint = 'D';
        for (int i = 0; i < abs (corA.first - corB.first); i++) xT += toPrint;
        string yT = "";
        toPrint = 'L';
        if (corA.second < corB.second) toPrint = 'R';
        for (int i = 0; i < abs (corA.second - corB.second); i++) yT += toPrint;
        if (a == 'z')   return xT + yT;
        else return yT + xT;
    }

    pair<int,int> mapCharToCor(char a) {
        return make_pair((a-'a')/5, (a-'a')%5);
    }
};