// Problem URL: https://leetcode.com/problems/contains-duplicate-iii/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set <long long int> st;
        map <long long int,long long int> mp;
        long long int n = nums.size();
        if (n == 0 || n == 1) return false;
        k = min((long long int)k,(long long int)n-1);
        // window set up
        for (int i=0; i<=k; i++)    {
            st.insert(nums[i]);
            mp[nums[i]]++;
        }
        // window
        for (int i=0;i<n;i++) {
            mp[nums[i]]--;
            if (!mp[nums[i]]) st.erase(nums[i]);
            set <long long int> :: iterator it;
            it = (st.lower_bound((long long int)nums[i]-(long long int)t));
            if (it != st.end() and abs((*it)-(long long int)nums[i]) <= t) return true;
            it = (st.lower_bound((long long int)nums[i]));
            if (it != st.end() and abs((*it)-(long long int)nums[i]) <= t) return true;

            if (i+k+1 < n) {
                mp[nums[i+k+1]]++;
                st.insert(nums[i+k+1]);
            }
        }
        return false;
    }
};