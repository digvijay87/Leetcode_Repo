/*
 * @lc app=leetcode id=1588 lang=cpp
 *
 * [1588] Sum of All Odd Length Subarrays
 */

// @lc code=start
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++)
        {
            int contributor = ceil((1+i)*(n-i)/2.0);
            res += contributor * arr[i];
        }
        return res;
    }
};
// @lc code=end

