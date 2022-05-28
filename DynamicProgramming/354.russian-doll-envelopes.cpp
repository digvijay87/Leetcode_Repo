/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 * #DailyChallange
 * #LIS
 * #DP
 * #DynamicProgramming
 */
/*
LIS:

Maximum Sum Increasing Subsequence
Print LIS
Best Team with No Conflicts (LC 1626)
No of LIS
Increasing Triplet Subsequence
LIS having sum almost K
Minimum Number of Removals to Make Mountain Array
*/

// @lc code=start
class Solution {
    struct comp {
    bool operator()(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0])
        {
            return a[1] > b[1];
        }else{
            return a[0] < b[0]; 
        }
    }
};
public:
    
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp()); 
             
        vector<int> dp;
        
        for (auto& x : envelopes) {
            int height = x[1];
            
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            if (left == dp.size()) dp.push_back(height);
            dp[left] = height;
        }
        return dp.size();
    }
};
// @lc code=end

