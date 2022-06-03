/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 * Similar question :: 216 Combination SumIII
 * [40] Combination Sum II
 * #Backtracking
 */

// @lc code=start
class Solution {
    void helper(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> temp, int start)
    {
        if(target == 0)
        {
            res.push_back(temp);
        }else{
            for(int i = start; i < candidates.size() and candidates[i] <= target; i++)
            {
                temp.push_back(candidates[i]);
                helper(candidates, target - candidates[i], res, temp, i);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        
        helper(candidates, target, res, temp, 0);
        return res;
    }
};
// @lc code=end

