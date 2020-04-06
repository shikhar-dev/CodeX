// Problem URL: https://leetcode.com/problems/monotone-increasing-digits/
class Solution {
private:
    string check(string n) {
        for (int i=0;i<n.size()-1;i++)
            if (n[i] > n[i+1]) {
                n[i]--;
                for (int j = i+1; j < n.size(); j++) n[j] ='9';
            }
        return n;
    }
public:
    int monotoneIncreasingDigits(int N) {
        string a = to_string(N),n;
        do {
            n = a;
            a = check(n);
        } while (a != n);
        int sum = 0;
        for (auto x: n) sum = sum*10 + (x-'0');
        return sum;
    }
};