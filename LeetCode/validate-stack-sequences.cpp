// Problem URL: https://leetcode.com/problems/validate-stack-sequences/
class Solution {
private:
    stack <int> st;
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i,j;
        for (i=0, j=0;j < popped.size();) {

            while ((st.empty() || st.top() != popped[j]) and i < pushed.size()) {
                st.push(pushed[i++]);
            }

            if (st.empty()  || st.top() != popped[j]) return false;

            st.pop();
            j++;

        }
        return true;
    }
};