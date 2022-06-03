/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 * Similar question
 * #BackTrack
 * [39] Combination Sum
 * [216] Combination Sum III
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
                if(i == start || candidates[i] != candidates[i-1]){
                    temp.push_back(candidates[i]);
                    helper(candidates, target - candidates[i], res, temp, i+1);
                    temp.pop_back();
                }
                
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        
        helper(candidates, target, res, temp, 0);
        return res;
    }
};
// @lc code=end

