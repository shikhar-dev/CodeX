// Problem URL: https://leetcode.com/problems/next-greater-element-iii/
class Solution {
public:
    int nextGreaterElement(int n) {
        vector <long long int> num;
        long long int storeN = n;
        while (n) {
            num.push_back(n%10);
            n /= 10;
        }
        for (int i=1; i<num.size();i++)
            if (num[i-1] > num[i])  {
                int j;
                for (j = 0; j < i; j++)
                    if (num[j] > num[i]) break;
                swap(num[j],num[i]);
                for (j=0;j<i/2;j++) swap(num[j],num[i-1-j]);
                break;
            }
        reverse(num.begin(),num.end());
        long long int ans = 0;
        for (auto x: num)   ans = ans * 10 + x;
        if (ans == storeN || ans > 2147483648)  return -1;
        return ans;
    }
};