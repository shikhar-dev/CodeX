// Problem URL: https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector <pair<int,int>> ans;
        vector <int> vec;

        for (auto x: restaurants)
            if (!((veganFriendly == 1 and x[2]==0) || (x[3] > maxPrice) || (x[4] > maxDistance))) {
                ans.push_back(make_pair(x[1],x[0]));
            }
        
        sort(ans.begin(),ans.end(),greater<pair<int,int>>());
        for (auto x: ans)
            vec.push_back(x.second);
        return vec;
    }
};