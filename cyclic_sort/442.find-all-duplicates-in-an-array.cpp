/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 * #Cyclic Sort
 * #Dailychallange
 * Similar question :: 
 * 448. Find All Numbers Disappeared in an Array
 * 41. First Missing Positive
 * 442. Find All Duplicates in an Array
 * 268. Missing Number
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        int n = nums.size();
        
        while(i < n)
        {
            if(nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
            else{
                i++;
            }
        }
        
        for(int i = 0; i <n; i++)
        {
            if(nums[i] != i+1)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
// @lc code=end

