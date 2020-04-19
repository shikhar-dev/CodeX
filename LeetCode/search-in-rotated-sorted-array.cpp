// Problem URL: https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
private:
    int bs(int l,int u, int num, vector <int> & nums) {
        int m = (u+l)/2;
        if (u < l) return u;
        if (nums[m] <= num)  return bs(l,m-1,num,nums);
        else return bs(m+1,u,num,nums);
    }
    int mainBS(int l, int u, int item, vector <int> & nums) {
        int m = (u+l)/2;
        if (nums[m] == item) return m;
        if (u < l) return -1;
        if (nums[m] > item) return mainBS(l,m-1,item,nums);
        else return mainBS(m+1,u,item,nums);
    }
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        if (nums.size() == 1)   return (target == nums[0]) ? 0 : -1;
        if (nums[0] < nums[nums.size()-1])  return mainBS(0,nums.size()-1,target,nums);
        else {
            int pivot = bs(0,nums.size()-1, nums.back(), nums);
            if (target <= nums.back())  return mainBS(pivot+1,nums.size()-1,target,nums);
            else return mainBS(0,pivot,target,nums);
        }
    }
};